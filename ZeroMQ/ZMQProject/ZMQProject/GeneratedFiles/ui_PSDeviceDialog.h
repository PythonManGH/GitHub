/********************************************************************************
** Form generated from reading UI file 'PSDeviceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSDEVICEDIALOG_H
#define UI_PSDEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PSDeviceDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *teServer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *teDevice;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *teClient;

    void setupUi(QDialog *PSDeviceDialog)
    {
        if (PSDeviceDialog->objectName().isEmpty())
            PSDeviceDialog->setObjectName(QStringLiteral("PSDeviceDialog"));
        PSDeviceDialog->resize(1383, 615);
        horizontalLayout = new QHBoxLayout(PSDeviceDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(PSDeviceDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        teServer = new QTextEdit(groupBox);
        teServer->setObjectName(QStringLiteral("teServer"));

        verticalLayout->addWidget(teServer);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PSDeviceDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        teDevice = new QTextEdit(groupBox_2);
        teDevice->setObjectName(QStringLiteral("teDevice"));

        verticalLayout_2->addWidget(teDevice);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(PSDeviceDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        teClient = new QTextEdit(groupBox_3);
        teClient->setObjectName(QStringLiteral("teClient"));

        verticalLayout_3->addWidget(teClient);


        horizontalLayout->addWidget(groupBox_3);


        retranslateUi(PSDeviceDialog);

        QMetaObject::connectSlotsByName(PSDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *PSDeviceDialog)
    {
        PSDeviceDialog->setWindowTitle(QApplication::translate("PSDeviceDialog", "PSDeviceDialog", 0));
        groupBox->setTitle(QApplication::translate("PSDeviceDialog", "Server", 0));
        groupBox_2->setTitle(QApplication::translate("PSDeviceDialog", "Device", 0));
        groupBox_3->setTitle(QApplication::translate("PSDeviceDialog", "Client", 0));
    } // retranslateUi

};

namespace Ui {
    class PSDeviceDialog: public Ui_PSDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSDEVICEDIALOG_H
