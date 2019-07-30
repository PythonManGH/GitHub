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

	class PS01Server*              mpServer;                    //<! ������Ϣ�Ŀͻ���
	class PSDevice*                mpDevice;                    //<! ����ת����Ϣ��
	QVector<class PS01Client*>     mvClient;                    //<! ֱ�ӽ�����Ϣ�Ŀͻ��� 
	QVector<class PS01Client*>     mvSubClient;                 //<! ��װ���н�����Ϣ�Ŀͻ��� 
};
