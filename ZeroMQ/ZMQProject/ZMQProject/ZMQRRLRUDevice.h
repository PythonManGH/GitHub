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
	class ZMQServer*      mpFrontEnd;                    //<! ǰ�˶˵�
	class ZMQServer*      mpBackEnd;                     //<! ��˶˵�
	void*                 mpContext;                     //<! �����Ļ���	
	list<char*>           mListServer;                   //<! ��¼�ͱ��浱ǰ�Ŀ���Server
};

