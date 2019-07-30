#pragma once

#include <QThread>

class ZPClient : public QThread
{
	Q_OBJECT

public:
	ZPClient(QObject *parent);
	~ZPClient();

	virtual void run();

	void setName(QString _name);

signals:
	void value(QString);

private:
	class ZMQClient*          mpReq;
	class ZMQClient*          mpSub;
};
