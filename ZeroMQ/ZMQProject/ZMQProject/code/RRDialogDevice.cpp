#include "RRDialogDevice.h"
#include"RRDevice.h"
#include"RRLRUDevice.h"
#include"BaseDefine.h"
#include"RRServer.h"
#include"RRClient.h"
#include"zmq.h"
RRDialogDevice::RRDialogDevice(QWidget *parent)
	: QDialog(parent),mpDevice(new RRDevice(this))
{
	ui.setupUi(this);
	void* context = zmq_init(1);

	mpDevice->initTo(RR02_FRONT,RR02_BACK,context);
	mpDevice->start();


	for (int i = 0; i < 5; i++)
	{
		RRServer *server = new RRServer(this);
		server->connectToDealer(RR02_BACK, context);
		server->setName(QString::asprintf("server-%d", i));
		connect(server,SIGNAL(value(QString)),this,SLOT(slotServer(QString)));
		server->start();
		mvServer.push_back(server);
	}

	for (int i = 0; i < 10; i++)
	{
		RRClient *client = new RRClient(this);
		client->setName(QString::asprintf("client-%d",i));
		client->initTo(RR02_FRONT, context);
		connect(client, SIGNAL(value(QString)), this, SLOT(slotClient(QString)));
		client->start();
		mvClient.push_back(client);
	}
}

RRDialogDevice::~RRDialogDevice()
{
}

void RRDialogDevice::slotServer(QString _str)
{
	ui.teRep->append(_str);
}
void RRDialogDevice::slotClient(QString _str)
{
	ui.teReq->append(_str);
}
