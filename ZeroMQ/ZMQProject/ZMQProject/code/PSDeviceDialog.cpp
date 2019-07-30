#include "PSDeviceDialog.h"
#include"PS01Server.h"
#include"PSDevice.h"
#include"PS01Client.h"
#include"BaseDefine.h"

PSDeviceDialog::PSDeviceDialog(QWidget *parent)
	: QDialog(parent), mpServer(new PS01Server(this)), mpDevice(new PSDevice(this))
{
	ui.setupUi(this);
	mpServer->initTo(PSDEVICE_FRONT);
	mpServer->start();
	mpDevice->initTo(PSDEVICE_FRONT, PSDEVICE_BACE);
	mpDevice->start();

	connect(mpServer, SIGNAL(value(QString)), this, SLOT(slotServer(QString)));
	connect(mpDevice, SIGNAL(value(QString)), this, SLOT(slotDevice(QString)));

	for (int i = 0; i < 5; i++)
	{
		PS01Client *client = new PS01Client(this);
		client->initTo(PSDEVICE_FRONT);
		client->setName(QString::fromLocal8Bit("Server接受了"));
		connect(client, SIGNAL(value(QString)), this, SLOT(slotClient(QString)));
		client->start();
		mvClient.push_back(client);


		PS01Client *sclient = new PS01Client(this);
		sclient->initTo(PSDEVICE_BACE);
		sclient->setName(QString::fromLocal8Bit("Device接受了"));
		connect(sclient, SIGNAL(value(QString)), this, SLOT(slotClient(QString)));
		sclient->start();
		mvSubClient.push_back(sclient);
	}
}

PSDeviceDialog::~PSDeviceDialog()
{
}

void PSDeviceDialog::slotServer(QString _str)
{
	ui.teServer->append(_str);
}
void PSDeviceDialog::slotDevice(QString _str)
{
	ui.teDevice->append(_str);
}
void PSDeviceDialog::slotClient(QString _str)
{
	ui.teClient->append(_str);
}
