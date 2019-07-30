#include "PSServer.h"
#include"ZMQServer.h"
PSServer::PSServer(QObject *parent)
	: QThread(parent), mpPub(new ZMQServer)
{
}

PSServer::~PSServer()
{
}

void PSServer::run()
{
	int index = 0;
	while (true)
	{
		int i = rand() % 10;
		char ch[4];
		sprintf(ch, "%d", i);
		mpPub->sendMoreMsg(ch);

		char chc[128];
		sprintf(chc, "我发布了第%d条消息**地址是%s", index, ch);
		mpPub->sendMsg(chc);
		emit value(QString::fromLocal8Bit(chc));
		index++;
		Sleep(2000);
	}
}

void PSServer::initTo(char * _end, void * _context)
{
	mpPub->init(ZMQ_PUB,_context);
	mpPub->bind(_end);
}
