#pragma once

#include <QThread>

class PS01Client : public QThread
{
	Q_OBJECT

public:
	PS01Client(QObject *parent);
	~PS01Client();

	virtual void run();
	void initTo(char* _end);

	void setName(QString _name);

signals:
	void value(QString);


private:
	class ZMQBase*            mpSub;                 //<!  ��򵥵ķ�������ģʽ�е�  ����    
	QString                   mName;
};
