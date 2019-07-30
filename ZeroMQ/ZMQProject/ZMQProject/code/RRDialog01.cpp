#include "RRDialog01.h"
#include"RRServer.h"
#include"RRClient.h"
#include"BaseDefine.h"

RRDialog01::RRDialog01(QWidget *parent)
	: QDialog(parent),mpServer(new RRServer(this))
{
	ui.setupUi(this);

	mpServer->initTo(RR01);
	mpServer->start();
	connect(mpServer,SIGNAL(value(QString)),this,SLOT(slotServer(QString)));

	for (int i = 0; i < 10; i++)
	{
		RRClient *client = new RRClient(this);
		char ch[128];
		sprintf(ch,"client-%d",i);
		client->setName(QString::fromLocal8Bit(ch));
		client->initTo(RR01);
		connect(client, SIGNAL(value(QString)), this, SLOT(slotClient(QString)));
		client->start();
		mvClient.push_back(client);
	}
}

RRDialog01::~RRDialog01()
{
	if (mpServer)
	{
		delete mpServer;
		mpServer = nullptr;
	}
}

void RRDialog01::slotServer(QString _str)
{
	ui.teRep->append(_str);
}

void RRDialog01::slotClient(QString _str)
{
	ui.teReq->append(_str);
}
