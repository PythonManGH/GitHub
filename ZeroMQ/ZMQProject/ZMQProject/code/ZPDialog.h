#pragma once

#include <QDialog>
#include "ui_ZPDialog.h"

class ZPDialog : public QDialog
{
	Q_OBJECT

public:
	ZPDialog(QWidget *parent = Q_NULLPTR);
	~ZPDialog();
	private slots:
	void slotClient(QString);
	void slotServerReq(QString);
	void slotServerPub(QString);

private:
	Ui::ZPDialog ui;

	class ZPClient*          mpClient;
	class ZPServerRep*       mpRep;
	class ZPServerPub*       mpPub;
};
