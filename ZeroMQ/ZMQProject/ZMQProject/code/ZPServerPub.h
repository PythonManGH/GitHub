#pragma once

#include <QThread>

class ZPServerPub : public QThread
{
	Q_OBJECT

public:
	ZPServerPub(QObject *parent);
	~ZPServerPub();

	virtual void run();

signals:
	void value(QString);

private:
	class ZMQServer*                   mpPub;
};
