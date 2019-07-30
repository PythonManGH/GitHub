#include "MainWindow.h"
#include"PSDialog.h"
#include"ZPDialog.h"
#include"PSDeviceDialog.h"
#include"RRDialogDevice.h"
#include"PSEnvelopeDialog.h"
#include"RRDialog01.h"
#include"BaseDefine.h"
#include"zmq.h"
void* gContext=nullptr;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), mpPSDialog1(nullptr),mpZPDialog(nullptr), mpPSDevice(nullptr), mpDialog01(nullptr), mpEnvelope(nullptr),
	mpRRDialogDevice(nullptr)
{
	ui.setupUi(this);
	gContext = zmq_init(1);
	connect(ui.actionPubSub01,SIGNAL(triggered(bool)),this,SLOT(slotActionPubSub01(bool)));//triggered(bool)
	connect(ui.actionPubSub02, SIGNAL(triggered(bool)), this, SLOT(slotActionPubSub02(bool)));//triggered(bool)
	connect(ui.action_zmq_poll, SIGNAL(triggered(bool)), this, SLOT(slotActionZP(bool)));
	connect(ui.actionReq_rep_01, SIGNAL(triggered(bool)), this, SLOT(slotActionRR01(bool)));
	connect(ui.actionReq_rep_02, SIGNAL(triggered(bool)), this, SLOT(slotActionRR02(bool)));
	connect(ui.actionPs02, SIGNAL(triggered(bool)), this, SLOT(slotActionPs02(bool)));
	
}

void MainWindow::slotActionPubSub01(bool _value)
{
	if (!mpPSDialog1)
		mpPSDialog1 = new PSDialog(this);
	mpPSDialog1->show();
}


void MainWindow::slotActionPubSub02(bool _value)
{
	if (!mpPSDevice)
		mpPSDevice = new PSDeviceDialog(this);
	mpPSDevice->show();
}

void MainWindow::slotActionZP(bool _value)
{
	if (!mpZPDialog)
		mpZPDialog = new ZPDialog(this);
	mpZPDialog->show();
}

void MainWindow::slotActionRR01(bool _value)
{
	if (!mpDialog01)
		mpDialog01 = new RRDialog01(this);
	mpDialog01->show();
}

void MainWindow::slotActionRR02(bool _value)
{
	if (!mpRRDialogDevice)
		mpRRDialogDevice = new RRDialogDevice(this);
	mpRRDialogDevice->show();
}

void MainWindow::slotActionPs02(bool _value)
{
	if (!mpEnvelope)
		mpEnvelope = new PSEnvelopeDialog(this);
	mpEnvelope->show();
}
