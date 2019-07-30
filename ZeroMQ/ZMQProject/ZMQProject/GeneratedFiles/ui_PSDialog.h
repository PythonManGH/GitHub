/********************************************************************************
** Form generated from reading UI file 'PSDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSDIALOG_H
#define UI_PSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PSDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *tePub;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leTxt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *sbNum;
    QPushButton *btnPub;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *teSub;

    void setupUi(QDialog *PSDialog)
    {
        if (PSDialog->objectName().isEmpty())
            PSDialog->setObjectName(QStringLiteral("PSDialog"));
        PSDialog->resize(1451, 697);
        horizontalLayout_5 = new QHBoxLayout(PSDialog);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox = new QGroupBox(PSDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tePub = new QTextEdit(groupBox);
        tePub->setObjectName(QStringLiteral("tePub"));

        verticalLayout_2->addWidget(tePub);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        leTxt = new QLineEdit(groupBox);
        leTxt->setObjectName(QStringLiteral("leTxt"));

        horizontalLayout_2->addWidget(leTxt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_2);

        sbNum = new QSpinBox(groupBox);
        sbNum->setObjectName(QStringLiteral("sbNum"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbNum->sizePolicy().hasHeightForWidth());
        sbNum->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(sbNum);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        btnPub = new QPushButton(groupBox);
        btnPub->setObjectName(QStringLiteral("btnPub"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnPub->sizePolicy().hasHeightForWidth());
        btnPub->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(btnPub);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PSDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        teSub = new QTextEdit(groupBox_2);
        teSub->setObjectName(QStringLiteral("teSub"));

        horizontalLayout->addWidget(teSub);


        horizontalLayout_5->addWidget(groupBox_2);


        retranslateUi(PSDialog);

        QMetaObject::connectSlotsByName(PSDialog);
    } // setupUi

    void retranslateUi(QDialog *PSDialog)
    {
        PSDialog->setWindowTitle(QApplication::translate("PSDialog", "PSDialog", 0));
        groupBox->setTitle(QApplication::translate("PSDialog", "\345\217\221\345\270\203\346\266\210\346\201\257", 0));
        label->setText(QApplication::translate("PSDialog", "\345\206\205\345\256\271\357\274\232", 0));
        label_2->setText(QApplication::translate("PSDialog", "\346\225\260\351\207\217\357\274\232", 0));
        btnPub->setText(QApplication::translate("PSDialog", "\345\217\221\345\270\203", 0));
        groupBox_2->setTitle(QApplication::translate("PSDialog", "\350\256\242\351\230\205\346\266\210\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class PSDialog: public Ui_PSDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSDIALOG_H
