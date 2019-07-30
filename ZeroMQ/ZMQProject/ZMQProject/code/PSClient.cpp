#include "PSClient.h"
#include"ZMQClient.h"

PSClient::PSClient(QObject *parent)
	: QThread(parent),mpSub(new ZMQClient)
{
}

PSClient::~PSClient()
{
}

void PSClient::run()
{
	while (true)
	{
		char* addre = mpSub->recvMsg();
		char a[128];
		sprintf(a,"*****address*****%s", addre);
		emit value(mName + QString::fromLocal8Bit(a));

		char* content = mpSub->recvMsg();
		char an[128];
		sprintf(an, "*****content*****%s", content);
		emit value(mName + QString::fromLocal8Bit(an));
	}
}

void PSClient::initTo(char * _end, void * _context)
{
	if (mpSub)
	{
		mpSub->init(ZMQ_SUB,_context);
		mpSub->connect(_end);
		
	}
}

void PSClient::setName(QString _name)
{
	mName = _name;
}

void PSClient::setFilter(char * _filter)
{
	if (mpSub)
	{
		mpSub->setsockopt(ZMQ_SUBSCRIBE,_filter,strlen(_filter));
	}
}
