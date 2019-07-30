#include "ZPServerRep.h"
#include"ZMQServer.h"
#include"BaseDefine.h"
extern void* gContext;
ZPServerRep::ZPServerRep(QObject *parent)
	: QThread(parent),mpRep(nullptr)
{
	mpRep = new ZMQServer;
	mpRep->init(ZMQ_REP, gContext);
	mpRep->bind(ZP01RR_ENDPOINT);
}

ZPServerRep::~ZPServerRep()
{
	if (mpRep)
	{
		delete mpRep;
		mpRep = nullptr;
	}
}

void ZPServerRep::run()
{
	while (1)
	{
		char *ch = mpRep->recvMsg();
		Sleep(5000);

		char ch1[] = "Req";
		mpRep->sendMsg(ch1);
		emit value(QString::fromLocal8Bit("I send ") + QString::fromLocal8Bit(ch1));
	}
}
