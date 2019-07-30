#pragma once

#include <QThread>

class PSClient : public QThread
{
	Q_OBJECT

public:
	PSClient(QObject *parent);
	~PSClient();

	virtual void run();
	void initTo(char* _end,void* _context);
	void setName(QString _name);
	void setFilter(char* _filter);
signals:
	void value(QString);


private:
	class ZMQClient*          mpSub;
	QString                   mName;
};
