#pragma once

#include <QThread>

class RRDevice : public QThread
{
	Q_OBJECT

public:
	RRDevice(QObject *parent);
	~RRDevice();

	virtual void run();
	void initTo(char* _front, char* _back);
	void initTo(char* _front, char* _back,void* _context);

signals:
	void value(QString);

private:
	class ZMQRRDevice*          mpDevice;
};
