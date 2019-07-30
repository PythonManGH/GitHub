#pragma once

#include <QThread>

class RRClient : public QThread
{
	Q_OBJECT

public:
	RRClient(QObject *parent);
	~RRClient();

	void initTo(char* _end);
	void initTo(char* _end,void* _context);
	virtual void run();
	void setName(QString _name);

signals:
	void value(QString);

private:
	class ZMQBase*            mpReq;                 
	QString                   mName;
};
