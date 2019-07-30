#pragma once

#include <QThread>

class PS01Server : public QThread
{
	Q_OBJECT

public:
	PS01Server(QObject *parent);
	~PS01Server();

	virtual void run();
	void initTo(char* _end);

signals:
	void value(QString);


private:
	class ZMQBase*            mpPub;                 //<!  ��򵥵ķ�������ģʽ�е�  ����
};
