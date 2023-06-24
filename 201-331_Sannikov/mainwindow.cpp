#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"
#include "qaesencryption.h"
#include <QMessageBox>
#include <QFile>
#include "QCryptographicHash"
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_pin(QString pinCode)
{
    QFile file("D:/encoded.json");
    if (!file.exists()) {
        auto encodedPin = crypto::encrypt((pinCode).toUtf8(), pinCode, pinCode);

        file.open(QIODevice::ReadWrite | QIODevice::Text);
        file.write(encodedPin);
        file.close();

        QMessageBox::warning(this, "Pin", "A new PIN code has been created");
        qDebug()<< "encodedPin" << encodedPin;
    }
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray readedText = file.readAll();
    file.close();

    QString decodedText = crypto::decrypt(readedText, pinCode, pinCode);
    return pinCode == decodedText;
}

void MainWindow::on_pushButton_clicked()
{
    QString pinCode = ui->pincode->text();


    if(check_pin(pinCode))
    {
        sWindow = new promocodes(pinCode);
        sWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"Авторизация","Неправильный пин-код");
    }
}



