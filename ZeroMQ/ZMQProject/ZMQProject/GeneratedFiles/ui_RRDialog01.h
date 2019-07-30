/********************************************************************************
** Form generated from reading UI file 'RRDialog01.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RRDIALOG01_H
#define UI_RRDIALOG01_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RRDialog01
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *teRep;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *teReq;

    void setupUi(QWidget *RRDialog01)
    {
        if (RRDialog01->objectName().isEmpty())
            RRDialog01->setObjectName(QStringLiteral("RRDialog01"));
        RRDialog01->resize(980, 644);
        horizontalLayout = new QHBoxLayout(RRDialog01);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(RRDialog01);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        teRep = new QTextEdit(groupBox);
        teRep->setObjectName(QStringLiteral("teRep"));

        verticalLayout->addWidget(teRep);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(RRDialog01);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        teReq = new QTextEdit(groupBox_2);
        teReq->setObjectName(QStringLiteral("teReq"));

        verticalLayout_2->addWidget(teReq);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(RRDialog01);

        QMetaObject::connectSlotsByName(RRDialog01);
    } // setupUi

    void retranslateUi(QWidget *RRDialog01)
    {
        RRDialog01->setWindowTitle(QApplication::translate("RRDialog01", "RRDialog01", 0));
        groupBox->setTitle(QApplication::translate("RRDialog01", "Server", 0));
        groupBox_2->setTitle(QApplication::translate("RRDialog01", "Client", 0));
    } // retranslateUi

};

namespace Ui {
    class RRDialog01: public Ui_RRDialog01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RRDIALOG01_H
