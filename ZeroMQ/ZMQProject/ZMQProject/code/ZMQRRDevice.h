///////////////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// Copyright (c) SGRI
/// All rights reserved
///
/// @file      ZMQRRDevice.h
/// @brief     Encapsulates ZeroMQ, the device of REQ-REP
/// @author    LiuJun
/// @date      2019/7/24
//////////////////////////////////////////////////////////////////////////////////

#pragma once

class ZMQRRDevice
{
public:
	ZMQRRDevice();
	~ZMQRRDevice();

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
	virtual void initTo(char* _frontend, char* _backend, void* _context);

	/*
	* @brief:Used to process message
	*/
	void processMsg();

private:
	class ZMQServer*      mpFrontEnd;                    //<! 前端端点
	class ZMQServer*      mpBackEnd;                     //<! 后端端点
	void*                 mpContext;                     //<! 上下文环境
};

