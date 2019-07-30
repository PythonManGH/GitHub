#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::MainWindowClass ui;


	private slots:
	void slotActionPubSub01(bool _value);  // ��򵥵��źźͲܺ���
	void slotActionPubSub02(bool _value);  // ����װ�õķ�������
	void slotActionZP(bool _value);        // ������socket������Ϣ
	void slotActionRR01(bool _value);      // �򵥵�����Ӧ��
	void slotActionRR02(bool _value);      // ��������-Ӧ�����
	void slotActionPs02(bool _value);      // ����-������Ϣ�ŷ�
	


private:
	class PSDialog*                mpPSDialog1;
	class ZPDialog*                mpZPDialog;
	class PSDeviceDialog*          mpPSDevice;
	class RRDialog01*              mpDialog01;
	class RRDialogDevice*          mpRRDialogDevice;
	class PSEnvelopeDialog*        mpEnvelope;
};
