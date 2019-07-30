#pragma once
#include<list>
using namespace std;

class ZMQRRLRUDevice
{
public:
	ZMQRRLRUDevice();
	~ZMQRRLRUDevice();


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
	list<char*>           mListServer;                   //<! 记录和保存当前的空闲Server
};

