#include "promocodes.h"
#include "ui_promocodes.h"
#include <QRandomGenerator>
#include <qDebug>
#include <QString>
promocodes::promocodes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::promocodes)
{
    ui->setupUi(this);
    initPromo();
}

promocodes::~promocodes()
{
    delete ui;
}



QString promocodes::generateRandomString(int length)
{
    QString randomString;
    randomString.reserve(length);

    for (int i = 0; i < length; ++i) {
        // Генерируем случайное число от 0 до 255
        int randomValue = QRandomGenerator::global()->bounded(36);
        // Преобразуем случайное число в символ
        QChar randomChar;
        if (randomValue < 10) {
            randomChar = QChar('0' + randomValue); // цифры 0-9
        } else {
            randomChar = QChar('A' + (randomValue - 10)); // буквы A-Z
        }
        // Добавляем символ к строке
        randomString.append(randomChar);
    }
    qDebug() << randomString;
    return randomString;
}

void promocodes::initPromo() {
    ui->listWidget->clear();

    for (uint i = 0; i < fieldSize; i++) {
        auto promo = generateRandomString(4);
        promos.append(promo);
//        addCard(promo);
    }
}

void promocodes::addCard(QString promo) {
    auto listItemW = new QListWidgetItem();
    auto itemW = new CardWidget(promo, this);

    listItemW->setSizeHint(itemW->sizeHint());

    ui->listWidget->addItem(listItemW);
    ui->listWidget->setItemWidget(listItemW, itemW);
}

void promocodes::on_pushButton_clicked()
{

}

