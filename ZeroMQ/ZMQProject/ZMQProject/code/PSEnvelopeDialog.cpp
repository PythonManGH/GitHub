#include "PSEnvelopeDialog.h"
#include"zmq.h"
#include"PSServer.h"
#include"PSClient.h"
#include"BaseDefine.h"

PSEnvelopeDialog::PSEnvelopeDialog(QWidget *parent)
	: QDialog(parent),mpServer(nullptr)
{
	void* context = zmq_init(1);

	mpServer = new PSServer(this);
	mpServer->initTo(PSENVELOPE,context);
	connect(mpServer,SIGNAL(value(QString)),SLOT(slotServer(QString)));
	mpServer->start();


	for (int i = 0; i < 9; i++)
	{
		PSClient* client = new PSClient(this);
		char ch[4];
		sprintf(ch,"%d",i);
		client->initTo(PSENVELOPE,context);
		client->setFilter(ch);
		connect(client, SIGNAL(value(QString)), SLOT(slotClient(QString)));
		client->start();
		mvClient.push_back(client);
	}

	ui.setupUi(this);
}

PSEnvelopeDialog::~PSEnvelopeDialog()
{
}

void PSEnvelopeDialog::slotClient(QString _str)
{
	ui.teSub->append(_str);
}
void PSEnvelopeDialog::slotServer(QString _str)
{
	ui.tePub->append(_str);
}