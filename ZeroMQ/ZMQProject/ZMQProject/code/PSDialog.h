#pragma once

#include <QDialog>
#include "ui_PSDialog.h"
#include<QVector>


class PSDialog : public QDialog
{
	Q_OBJECT

public:
	PSDialog(QWidget *parent = Q_NULLPTR);
	~PSDialog();

	private slots:
	void slotClientValue(QString _str);
	void slotServerValue(QString _str);

private:
	Ui::PSDialog ui;

	QVector<class PS01Client*>        mvClient;
	class   PS01Server*        mpServer;
};
