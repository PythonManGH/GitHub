#pragma once

#include <QThread>

class PSServer : public QThread
{
	Q_OBJECT

public:
	PSServer(QObject *parent);
	~PSServer();

	virtual void run();
	void initTo(char* _end,void* _context);
signals:
	void value(QString);
private:
	class ZMQServer*            mpPub;                
};
