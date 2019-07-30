#include "RRServer.h"
#include"ZMQServer.h"
extern void*  gContext;
RRServer::RRServer(QObject *parent)
	: QThread(parent),mpRep(new ZMQServer)
{
	
}

RRServer::~RRServer()
{

}

void RRServer::initTo(char * _end)
{
	mpRep->init(ZMQ_REP, gContext);
	mpRep->bind(_end);
}

void RRServer::connectToDealer(char * _endpoint)
{
	mpRep->init(ZMQ_REP, gContext);
	mpRep->connect(_endpoint);
}

void RRServer::connectToDealer(char * _endpoint, void * _context)
{
	mpRep->init(ZMQ_REP, _context);
	mpRep->connect(_endpoint);
}

void RRServer::run()
{
	while (1)
	{
		char* msg = mpRep->recvMsg();
		QString str = QString::fromLocal8Bit("我是") + mName + QString::fromLocal8Bit("正在处理--") + QString::fromLocal8Bit(msg);
		emit value(str);
		Sleep(5000);
		mpRep->sendMsg("OK");
	}
}

void RRServer::setName(QString _name)
{
	mName = _name;
}
