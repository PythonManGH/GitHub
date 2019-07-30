#include "RRDevice.h"
#include"ZMQRRDevice.h"
RRDevice::RRDevice(QObject *parent)
	: QThread(parent),mpDevice(new ZMQRRDevice)
{
}

RRDevice::~RRDevice()
{
}

void RRDevice::run()
{

	mpDevice->processMsg();
}

void RRDevice::initTo(char * _front, char * _back)
{
	mpDevice->initTo(_front, _back);
}

void RRDevice::initTo(char * _front, char * _back, void * _context)
{
	mpDevice->initTo(_front, _back, _context);
}
