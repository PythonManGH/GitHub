#include "PSDialog.h"
#include"PS01Client.h"
#include"PS01Server.h"
#include"BaseDefine.h"

PSDialog::PSDialog(QWidget *parent)
	: QDialog(parent), mpServer(new PS01Server(this))
{
	ui.setupUi(this);
	mpServer->initTo(PB01_ENDPOINT);
	for (int i = 0; i < 10; i++)
	{
		PS01Client *client = new PS01Client(this);
		client->setName(QString::asprintf("The %dth client",i));
		client->initTo(PB01_ENDPOINT);
		connect(client, SIGNAL(value(QString)), this, SLOT(slotClientValue(QString)));
		client->start();
		mvClient.push_back(client);
	}

	connect(mpServer, SIGNAL(value(QString)), this, SLOT(slotServerValue(QString)));
	
	mpServer->start();

	
}

PSDialog::~PSDialog()
{
}

void PSDialog::slotServerValue(QString _str)
{
	ui.tePub->append(_str);
}

void PSDialog::slotClientValue(QString _str)
{
	ui.teSub->append(_str);
}
