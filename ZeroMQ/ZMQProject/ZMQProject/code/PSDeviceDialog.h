#pragma once

#include <QDialog>
#include<QVector>
#include "ui_PSDeviceDialog.h"

class PSDeviceDialog : public QDialog
{
	Q_OBJECT

public:
	PSDeviceDialog(QWidget *parent = Q_NULLPTR);
	~PSDeviceDialog();

	private slots:
	void slotServer(QString _str);
	void slotDevice(QString _str);
	void slotClient(QString _str);

private:
	Ui::PSDeviceDialog ui;

	class PS01Server*              mpServer;                    //<! 发布消息的客户端
	class PSDevice*                mpDevice;                    //<! 用于转发消息的
	QVector<class PS01Client*>     mvClient;                    //<! 直接接受消息的客户端 
	QVector<class PS01Client*>     mvSubClient;                 //<! 从装置中接受消息的客户端 
};
