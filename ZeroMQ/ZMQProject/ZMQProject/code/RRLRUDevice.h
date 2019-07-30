#pragma once

#include <QThread>

class RRLRUDevice : public QThread
{
	Q_OBJECT

public:
	RRLRUDevice(QObject *parent);
	~RRLRUDevice();

	virtual void run();
	void initTo(char* _front, char* _back);
	void initTo(char* _front, char* _back, void* _context);

signals:
	void value(QString);

private:
	class ZMQRRLRUDevice*          mpDevice;
};
