#include "ZPClient.h"
#include"ZMQClient.h"
#include"BaseDefine.h"
extern void* gContext;
ZPClient::ZPClient(QObject *parent)
	: QThread(parent),mpReq(nullptr),mpSub(nullptr)
{
	mpReq = new ZMQClient();
	mpReq->init(ZMQ_REQ, gContext);
	mpReq->connect(ZP01RR_ENDPOINT);

	mpSub = new ZMQClient();
	mpSub->init(ZMQ_SUB, gContext);
	mpSub->connect(ZP01PS_ENDPOINT);

}

ZPClient::~ZPClient()
{
	if (mpReq)
	{
		delete mpReq;
		mpReq = nullptr;
	}
	if (mpSub)
	{
		delete mpSub;
		mpSub = nullptr;
	}
}

void ZPClient::run()
{
	if (mpSub && mpReq)
	{
		mpReq->sendMsg("000"); //先发送一个
		while (1)
		{
			zmq_pollitem_t items[] = {
				{ mpSub->socket(), 0, ZMQ_POLLIN, 0 },
				{ mpReq->socket(), 0, ZMQ_POLLIN, 0 }
			};
			zmq_poll(items, 2, -1);
			if (items[0].revents & ZMQ_POLLIN)
			{
				char* ch1 = mpSub->recvMsg();
				emit value(QString::fromLocal8Bit("Recv from ----------- ") + QString::fromLocal8Bit(ch1));
			}
			if (items[1].revents & ZMQ_POLLIN)
			{
				char* ch = mpReq->recvMsg();
				emit value(QString::fromLocal8Bit("Recv from --------------------- ") + QString::fromLocal8Bit(ch));
				mpReq->sendMsg("I'm Req");
			}
		}
	}
}

void ZPClient::setName(QString _name)
{
}
