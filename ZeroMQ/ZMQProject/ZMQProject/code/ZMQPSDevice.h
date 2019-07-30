///////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) SGRI
/// All rights reserved
///
/// @file      ZMQPSDevice.h
/// @brief     Encapsulates ZeroMQ, the device of PUB-SUB
/// @author    LiuJun
/// @date      2019/7/23
//////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "zmq.h"
#include "zhelpers.h"


class ZMQPSDevice
{
public:
	ZMQPSDevice();
	~ZMQPSDevice();


	/*
	* @brief:Creates socket and connects or binds to the specified IP and port
	* @param:_frontend("")
	* @param:_backend("")
	*/
	virtual void initTo(char* _frontend, char* _backend);

	/*
	* @brief:Used to inproc
	* @param:_frontend("")
	* @param:_backend("")
	*/
	virtual void initTo(char* _frontend, char* _backend,void* _context);

	/*
	* @brief:Used to process message
	*/
	char* processMsg();


private:
	/** @brief: send message */
	void sendMsg(char* _msg);

	/** @brief: recv message */
	char* recvMsg();


private:
	void*             mpFrontEnd;                    //<! 前端端点
	void*             mpBackEnd;                     //<! 后端端点
	void*             mpContext;                     //<! 上下文环境
};

