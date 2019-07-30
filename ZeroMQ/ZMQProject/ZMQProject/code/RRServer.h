#pragma once

#include <QThread>

class RRServer : public QThread
{
	Q_OBJECT

public:
	RRServer(QObject *parent);
	~RRServer();

	void initTo(char* _end);
	void connectToDealer(char* _endpoint);
	void connectToDealer(char* _endpoint, void* _context);
	virtual void run();
	void setName(QString _name);

signals:
	void value(QString);

private:
	class ZMQBase*            mpRep;                 //<!      
	QString                   mName;
};
