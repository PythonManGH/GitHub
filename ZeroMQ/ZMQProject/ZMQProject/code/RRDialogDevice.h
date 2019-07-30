#pragma once

#include <QDialog>
#include "ui_RRDialogDevice.h"

class RRDialogDevice : public QDialog
{
	Q_OBJECT

public:
	RRDialogDevice(QWidget *parent = Q_NULLPTR);
	~RRDialogDevice();

	private slots:
	void slotServer(QString);
	void slotClient(QString);

private:
	Ui::RRDialogDevice ui;

	QVector<class RRClient*>              mvClient;
	QVector<class RRServer*>              mvServer;
	class RRDevice*                       mpDevice;
};
