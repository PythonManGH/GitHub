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
	void slotActionPubSub01(bool _value);  // 最简单的信号和曹函数
	void slotActionPubSub02(bool _value);  // 带有装置的发布订阅
	void slotActionZP(bool _value);        // 处理多个socket接受消息
	void slotActionRR01(bool _value);      // 简单的请求应答
	void slotActionRR02(bool _value);      // 简易请求-应答代理
	void slotActionPs02(bool _value);      // 发布-订阅消息信封
	


private:
	class PSDialog*                mpPSDialog1;
	class ZPDialog*                mpZPDialog;
	class PSDeviceDialog*          mpPSDevice;
	class RRDialog01*              mpDialog01;
	class RRDialogDevice*          mpRRDialogDevice;
	class PSEnvelopeDialog*        mpEnvelope;
};
