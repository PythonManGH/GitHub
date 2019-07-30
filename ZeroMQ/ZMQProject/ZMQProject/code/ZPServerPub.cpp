#include "ZPServerPub.h"
#include"ZMQServer.h"
#include"BaseDefine.h"
extern void* gContext;
ZPServerPub::ZPServerPub(QObject *parent)
	: QThread(parent),mpPub(nullptr)
{
	mpPub = new ZMQServer;
	mpPub->init(ZMQ_PUB,gContext);
	mpPub->bind(ZP01PS_ENDPOINT);
}

ZPServerPub::~ZPServerPub()
{
	if (mpPub)
	{
		delete mpPub;
		mpPub = nullptr;
	}
}

void ZPServerPub::run()
{
	while (1)
	{
		char ch[] = "Pub";
		mpPub->sendMsg(ch);
		Sleep(1000);
		emit value(QString::fromLocal8Bit("I published ") + QString::fromLocal8Bit(ch));
		
	}
}
