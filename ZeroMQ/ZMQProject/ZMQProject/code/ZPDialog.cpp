#include "ZPDialog.h"
#include"ZPClient.h"
#include"ZPServerRep.h"
#include"ZPServerPub.h"

ZPDialog::ZPDialog(QWidget *parent)
	: QDialog(parent),mpClient(new ZPClient(this)), mpRep(new ZPServerRep(this)), mpPub(new ZPServerPub(this))
{
	ui.setupUi(this);
	connect(mpClient,SIGNAL(value(QString)),this,SLOT(slotClient(QString)));
	connect(mpRep, SIGNAL(value(QString)), this, SLOT(slotServerReq(QString)));
	connect(mpPub, SIGNAL(value(QString)), this, SLOT(slotServerPub(QString)));

	mpClient->start();
	mpRep->start();
	mpPub->start();
}

ZPDialog::~ZPDialog()
{
}
void ZPDialog::slotServerReq(QString _str)
{
	ui.teRep->append(_str);
}
void ZPDialog::slotServerPub(QString _str)
{
	ui.tePub->append(_str);
}
void ZPDialog::slotClient(QString _str)
{
	ui.teClient->append(_str);
}
