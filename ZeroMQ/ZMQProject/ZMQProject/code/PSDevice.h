#pragma once

#include <QThread>

class PSDevice : public QThread
{
	Q_OBJECT

public:
	PSDevice(QObject *parent);
	~PSDevice();

	virtual void run();
	void initTo(char* _front,char* _back);

signals:
	void value(QString);

private:
	class ZMQPSDevice*          mpDevice;
};
