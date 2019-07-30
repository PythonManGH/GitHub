#include "ZMQPSDevice.h"
#include<QDebug>


ZMQPSDevice::ZMQPSDevice()
	:mpFrontEnd(nullptr),mpBackEnd(nullptr), mpContext(nullptr)
{

}


ZMQPSDevice::~ZMQPSDevice()
{
}

void ZMQPSDevice::initTo(char * _frontend, char * _backend)
{
	mpContext = zmq_init(1);

	mpFrontEnd = zmq_socket(mpContext, ZMQ_SUB);
	zmq_connect(mpFrontEnd, _frontend);

	mpBackEnd = zmq_socket(mpContext, ZMQ_PUB);
	zmq_bind(mpBackEnd, _backend);
}

void ZMQPSDevice::initTo(char * _frontend, char * _backend, void * _context)
{
	mpFrontEnd = zmq_socket(_context, ZMQ_SUB);
	int res = zmq_connect(mpFrontEnd, _frontend);
	zmq_setsockopt(mpFrontEnd, ZMQ_SUBSCRIBE, "", 0);

	mpBackEnd = zmq_socket(_context, ZMQ_PUB);
	res = zmq_bind(mpBackEnd, _backend);
}

char* ZMQPSDevice::processMsg()
{
	char *str = recvMsg();
	sendMsg(str);
	return str;
}

void ZMQPSDevice::sendMsg(char * _msg)
{
	s_send(mpBackEnd, _msg);
}

char * ZMQPSDevice::recvMsg()
{
	return s_recv(mpFrontEnd);
}
