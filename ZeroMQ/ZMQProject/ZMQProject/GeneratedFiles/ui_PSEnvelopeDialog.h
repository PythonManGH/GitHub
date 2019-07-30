/********************************************************************************
** Form generated from reading UI file 'PSEnvelopeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSENVELOPEDIALOG_H
#define UI_PSENVELOPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_PSEnvelopeDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextEdit *tePub;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *teSub;

    void setupUi(QDialog *PSEnvelopeDialog)
    {
        if (PSEnvelopeDialog->objectName().isEmpty())
            PSEnvelopeDialog->setObjectName(QStringLiteral("PSEnvelopeDialog"));
        PSEnvelopeDialog->resize(1365, 694);
        horizontalLayout_3 = new QHBoxLayout(PSEnvelopeDialog);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(PSEnvelopeDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tePub = new QTextEdit(groupBox);
        tePub->setObjectName(QStringLiteral("tePub"));

        horizontalLayout->addWidget(tePub);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PSEnvelopeDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        teSub = new QTextEdit(groupBox_2);
        teSub->setObjectName(QStringLiteral("teSub"));

        horizontalLayout_2->addWidget(teSub);


        horizontalLayout_3->addWidget(groupBox_2);


        retranslateUi(PSEnvelopeDialog);

        QMetaObject::connectSlotsByName(PSEnvelopeDialog);
    } // setupUi

    void retranslateUi(QDialog *PSEnvelopeDialog)
    {
        PSEnvelopeDialog->setWindowTitle(QApplication::translate("PSEnvelopeDialog", "PSEnvelopeDialog", 0));
        groupBox->setTitle(QApplication::translate("PSEnvelopeDialog", "Server", 0));
        groupBox_2->setTitle(QApplication::translate("PSEnvelopeDialog", "Client", 0));
    } // retranslateUi

};

namespace Ui {
    class PSEnvelopeDialog: public Ui_PSEnvelopeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSENVELOPEDIALOG_H
