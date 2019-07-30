#include "RRLRUDevice.h"
#include"ZMQRRLRUDevice.h"

RRLRUDevice::RRLRUDevice(QObject *parent)
	: QThread(parent), mpDevice(new ZMQRRLRUDevice)
{
}

RRLRUDevice::~RRLRUDevice()
{
}

void RRLRUDevice::run()
{
	mpDevice->processMsg();
}

void RRLRUDevice::initTo(char * _front, char * _back)
{
	mpDevice->initTo(_front, _back);
}

void RRLRUDevice::initTo(char * _front, char * _back, void * _context)
{
	mpDevice->initTo(_front, _back, _context);
}
