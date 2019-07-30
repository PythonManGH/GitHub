#include "PS01Server.h"
#include"ZMQServer.h"

extern void* gContext;
PS01Server::PS01Server(QObject *parent)
	: QThread(parent), mpPub(new ZMQServer)
{
	
}

PS01Server::~PS01Server()
{
}

void PS01Server::run()
{
	int i = 0;
	while (1)
	{
		char ch[128];
		sprintf(ch,"������򵥵�PUB_SUB--%d",i);
		mpPub->sendMsg(ch);
		emit value(QString::fromLocal8Bit("�ҷ�����---------") + QString::fromLocal8Bit(ch));
		Sleep(1000);
		i++;
	}
}

void PS01Server::initTo(char * _end)
{
	mpPub->init(ZMQ_PUB, gContext);
	mpPub->bind(_end);
}
