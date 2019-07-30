#include "RRClient.h"
#include"ZMQClient.h"
extern void*  gContext;
RRClient::RRClient(QObject *parent)
	: QThread(parent),mpReq(new ZMQClient())
{
}

RRClient::~RRClient()
{
}

void RRClient::initTo(char * _end)
{
	mpReq->init(ZMQ_REQ, gContext);
	mpReq->setID(rand());
	mpReq->connect(_end);
}

void RRClient::initTo(char * _end, void * _context)
{
	mpReq->init(ZMQ_REQ, _context);
	mpReq->setID(rand());
	mpReq->connect(_end);
}

void RRClient::run()
{
	int i = 0;
	while (i<100)
	{
		char ch[128];
		sprintf(ch, "%s--%d",(const char*)(mName.toLocal8Bit()),i);
		mpReq->sendMsg(ch);
		emit value(mName + QString::fromLocal8Bit("***发布了")+QString::fromLocal8Bit(ch));
		
		char* str = mpReq->recvMsg();
		emit value(mName + QString::fromLocal8Bit("***接受了") + QString::fromLocal8Bit(str));
		
		i++;
	}
}

void RRClient::setName(QString _name)
{
	mName = _name;
}
