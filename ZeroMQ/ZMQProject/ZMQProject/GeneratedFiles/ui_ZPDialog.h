/********************************************************************************
** Form generated from reading UI file 'ZPDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZPDIALOG_H
#define UI_ZPDIALOG_H

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

class Ui_ZPDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *tePub;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *teRep;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QTextEdit *teClient;

    void setupUi(QDialog *ZPDialog)
    {
        if (ZPDialog->objectName().isEmpty())
            ZPDialog->setObjectName(QStringLiteral("ZPDialog"));
        ZPDialog->resize(1436, 630);
        horizontalLayout_3 = new QHBoxLayout(ZPDialog);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(ZPDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tePub = new QTextEdit(groupBox);
        tePub->setObjectName(QStringLiteral("tePub"));

        horizontalLayout_2->addWidget(tePub);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ZPDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        teRep = new QTextEdit(groupBox_2);
        teRep->setObjectName(QStringLiteral("teRep"));

        horizontalLayout->addWidget(teRep);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ZPDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        teClient = new QTextEdit(groupBox_3);
        teClient->setObjectName(QStringLiteral("teClient"));

        verticalLayout->addWidget(teClient);


        horizontalLayout_3->addWidget(groupBox_3);


        retranslateUi(ZPDialog);

        QMetaObject::connectSlotsByName(ZPDialog);
    } // setupUi

    void retranslateUi(QDialog *ZPDialog)
    {
        ZPDialog->setWindowTitle(QApplication::translate("ZPDialog", "ZPDialog", 0));
        groupBox->setTitle(QApplication::translate("ZPDialog", "\345\217\221\345\270\203", 0));
        groupBox_2->setTitle(QApplication::translate("ZPDialog", "\345\272\224\347\255\224", 0));
        groupBox_3->setTitle(QApplication::translate("ZPDialog", "Client", 0));
    } // retranslateUi

};

namespace Ui {
    class ZPDialog: public Ui_ZPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZPDIALOG_H
