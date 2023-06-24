/********************************************************************************
** Form generated from reading UI file 'promocodes.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOCODES_H
#define UI_PROMOCODES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_promocodes
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QListWidget *listWidget;

    void setupUi(QWidget *promocodes)
    {
        if (promocodes->objectName().isEmpty())
            promocodes->setObjectName("promocodes");
        promocodes->resize(400, 300);
        gridLayout = new QGridLayout(promocodes);
        gridLayout->setObjectName("gridLayout");
        pushButton = new QPushButton(promocodes);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        listWidget = new QListWidget(promocodes);
        listWidget->setObjectName("listWidget");

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);


        retranslateUi(promocodes);

        QMetaObject::connectSlotsByName(promocodes);
    } // setupUi

    void retranslateUi(QWidget *promocodes)
    {
        promocodes->setWindowTitle(QCoreApplication::translate("promocodes", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("promocodes", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\274\320\276\320\272\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class promocodes: public Ui_promocodes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOCODES_H
