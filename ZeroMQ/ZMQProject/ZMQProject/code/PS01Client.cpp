#include "PS01Client.h"
#include"ZMQBase.h"
#include"BaseDefine.h"

extern void* gContext;
PS01Client::PS01Client(QObject *parent)
	: QThread(parent), mpSub(new ZMQBase)
{
	
}

PS01Client::~PS01Client()
{
}

void PS01Client::run()
{
	while (1)
	{
		char * str = mpSub->recvMsg();
		emit value(mName + QString::fromLocal8Bit("***") + QString::fromLocal8Bit(str));
		Sleep(2000);
	}
}

void PS01Client::initTo(char * _end)
{
	mpSub->init(ZMQ_SUB, gContext);
	mpSub->setsockopt(ZMQ_SUBSCRIBE,"",0);
	mpSub->connect(_end);
}

void PS01Client::setName(QString _name)
{
	mName = _name;
}
