#pragma once

#include <QDialog>
#include "ui_PSEnvelopeDialog.h"

class PSEnvelopeDialog : public QDialog
{
	Q_OBJECT

public:
	PSEnvelopeDialog(QWidget *parent = Q_NULLPTR);
	~PSEnvelopeDialog();

	private slots:
	void slotClient(QString _str);
	void slotServer(QString _str);

private:
	Ui::PSEnvelopeDialog ui;

	class PSServer*         mpServer;
	QVector<class PSClient*> mvClient;
};
