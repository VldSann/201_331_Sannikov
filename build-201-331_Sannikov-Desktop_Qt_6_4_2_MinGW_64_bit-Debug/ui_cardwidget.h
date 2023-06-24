/********************************************************************************
** Form generated from reading UI file 'cardwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWIDGET_H
#define UI_CARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *promoButton;

    void setupUi(QWidget *CardWidget)
    {
        if (CardWidget->objectName().isEmpty())
            CardWidget->setObjectName("CardWidget");
        CardWidget->resize(100, 50);
        CardWidget->setMinimumSize(QSize(100, 50));
        CardWidget->setMaximumSize(QSize(100, 50));
        CardWidget->setBaseSize(QSize(100, 50));
        CardWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(CardWidget);
        gridLayout->setObjectName("gridLayout");
        promoButton = new QPushButton(CardWidget);
        promoButton->setObjectName("promoButton");
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(promoButton->sizePolicy().hasHeightForWidth());
        promoButton->setSizePolicy(sizePolicy);
        promoButton->setMinimumSize(QSize(82, 0));
        promoButton->setStyleSheet(QString::fromUtf8("*:hover{\n"
"background-color: gray;\n"
"}\n"
"QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"color: black\n"
"\n"
"}"));

        gridLayout->addWidget(promoButton, 0, 0, 1, 1);


        retranslateUi(CardWidget);

        QMetaObject::connectSlotsByName(CardWidget);
    } // setupUi

    void retranslateUi(QWidget *CardWidget)
    {
        CardWidget->setWindowTitle(QCoreApplication::translate("CardWidget", "Form", nullptr));
        promoButton->setText(QCoreApplication::translate("CardWidget", "9000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardWidget: public Ui_CardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWIDGET_H
