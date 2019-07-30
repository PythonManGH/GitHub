#include "ZMQRRLRUDevice.h"
#include"ZMQServer.h"


ZMQRRLRUDevice::ZMQRRLRUDevice()
	:mpFrontEnd(new ZMQServer), mpBackEnd(new ZMQServer), mpContext(nullptr)
{

}


ZMQRRLRUDevice::~ZMQRRLRUDevice()
{
}

void ZMQRRLRUDevice::initTo(char * _frontend, char * _backend)
{
	mpContext = zmq_init(1);

	mpFrontEnd->init(ZMQ_ROUTER, mpContext);
	mpFrontEnd->bind(_frontend);

	mpBackEnd->init(ZMQ_DEALER, mpContext);
	mpBackEnd->bind(_backend);
}

void ZMQRRLRUDevice::initTo(char * _frontend, char * _backend, void * _context)
{
	mpFrontEnd->init(ZMQ_ROUTER, _context);
	mpFrontEnd->bind(_frontend);

	mpBackEnd->init(ZMQ_DEALER, _context);
	mpBackEnd->bind(_backend);
}

void ZMQRRLRUDevice::processMsg()
{
	zmq_pollitem_t items[] = {
		{ mpFrontEnd->socket(), 0, ZMQ_POLLIN, 0 },
		{ mpBackEnd->socket(), 0, ZMQ_POLLIN, 0 }
	};
	while (1)
	{
		zmq_poll(items, 2, -1);
		if (items[1].revents & ZMQ_POLLIN)
		{
			while (1) {
				char* str = mpBackEnd->recvMsg();
				int64_t m = mpBackEnd->more();
				if (m)
				{
					mpFrontEnd->sendMoreMsg(str);
				}
				else
				{
					mpFrontEnd->sendMsg(str);
					break;
				}
			}
		}
		if (items[0].revents & ZMQ_POLLIN)
		{
			while (1) {
				char* str = mpFrontEnd->recvMsg();
				int64_t m = mpFrontEnd->more();
				if (m)
				{
					mpBackEnd->sendMoreMsg(str);
				}
				else
				{
					mpBackEnd->sendMsg(str);
					break;
				}
			}
		}
	}
}
