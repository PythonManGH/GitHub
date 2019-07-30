#pragma once

#include <QDialog>
#include "ui_RRDialog01.h"

class RRDialog01 : public QDialog
{
	Q_OBJECT

public:
	RRDialog01(QWidget *parent = Q_NULLPTR);
	~RRDialog01();

	private slots:
	void slotServer(QString);
	void slotClient(QString);

private:
	Ui::RRDialog01 ui;

	class RRServer*                mpServer;
	QVector<class RRClient*>       mvClient;
};
