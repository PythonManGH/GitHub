#include "PSDevice.h"
#include"ZMQPSDevice.h"
#include"BaseDefine.h"

extern void* gContext;
PSDevice::PSDevice(QObject *parent)
	: QThread(parent), mpDevice(nullptr)
{
	mpDevice = new ZMQPSDevice;
	
}

PSDevice::~PSDevice()
{
}

void PSDevice::run()
{
	while (1)
	{
		char *ch = mpDevice->processMsg();
		char ch1[128];
		sprintf(ch1, "我处理了消息------%s",ch);
		emit value(QString::fromLocal8Bit(ch1));
	}
}

void PSDevice::initTo(char * _front, char * _back)
{
	mpDevice->initTo(_front, _back,gContext);
}
