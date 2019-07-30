/********************************************************************************
** Form generated from reading UI file 'RRDialogDevice.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RRDIALOGDEVICE_H
#define UI_RRDIALOGDEVICE_H

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

class Ui_RRDialogDevice
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *teReq;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *teRD;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *teRep;

    void setupUi(QDialog *RRDialogDevice)
    {
        if (RRDialogDevice->objectName().isEmpty())
            RRDialogDevice->setObjectName(QStringLiteral("RRDialogDevice"));
        RRDialogDevice->resize(1453, 735);
        horizontalLayout = new QHBoxLayout(RRDialogDevice);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(RRDialogDevice);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        teReq = new QTextEdit(groupBox);
        teReq->setObjectName(QStringLiteral("teReq"));

        verticalLayout->addWidget(teReq);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(RRDialogDevice);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        teRD = new QTextEdit(groupBox_2);
        teRD->setObjectName(QStringLiteral("teRD"));

        verticalLayout_2->addWidget(teRD);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(RRDialogDevice);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        teRep = new QTextEdit(groupBox_3);
        teRep->setObjectName(QStringLiteral("teRep"));

        verticalLayout_3->addWidget(teRep);


        horizontalLayout->addWidget(groupBox_3);


        retranslateUi(RRDialogDevice);

        QMetaObject::connectSlotsByName(RRDialogDevice);
    } // setupUi

    void retranslateUi(QDialog *RRDialogDevice)
    {
        RRDialogDevice->setWindowTitle(QApplication::translate("RRDialogDevice", "RRDialogDevice", 0));
        groupBox->setTitle(QApplication::translate("RRDialogDevice", "Client", 0));
        groupBox_2->setTitle(QApplication::translate("RRDialogDevice", "Device", 0));
        groupBox_3->setTitle(QApplication::translate("RRDialogDevice", "Server", 0));
    } // retranslateUi

};

namespace Ui {
    class RRDialogDevice: public Ui_RRDialogDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RRDIALOGDEVICE_H
