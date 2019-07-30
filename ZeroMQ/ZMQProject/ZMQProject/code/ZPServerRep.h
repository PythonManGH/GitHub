#pragma once

#include <QThread>

class ZPServerRep : public QThread
{
	Q_OBJECT

public:
	ZPServerRep(QObject *parent);
	~ZPServerRep();

	virtual void run();

signals:
	void value(QString);

private:
	class ZMQServer*                   mpRep;
};
