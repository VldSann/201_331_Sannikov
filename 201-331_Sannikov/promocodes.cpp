#include "promocodes.h"
#include "ui_promocodes.h"
#include <QRandomGenerator>
#include <qDebug>
#include <QString>
promocodes::promocodes(QString pinCode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::promocodes)
{
    ui->setupUi(this);
    initPromo();
    this->pinCode = pinCode;
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
    auto encodedPromo = crypto::encrypt(randomString.toUtf8(), pinCode, pinCode);
    qDebug() << encodedPromo;
    return encodedPromo;
}

void promocodes::initPromo() {
    ui->listWidget->clear();

    for (uint i = 0; i < fieldSize; i++) {
        auto promo = generateRandomString(4);
        promos.append(promo);
        addCard(promo);
    }
}

void promocodes::addCard(QString promo) {
    auto listItemW = new QListWidgetItem();
    auto itemW = new CardWidget(pinCode, promo, this);

    listItemW->setSizeHint(itemW->sizeHint());

    ui->listWidget->addItem(listItemW);
    ui->listWidget->setItemWidget(listItemW, itemW);
}

void promocodes::on_pushButton_clicked()
{
    while (true) {
        auto randomIndex = QRandomGenerator::global()->bounded(uint(0), fieldSize);

        if (openedPromos.contains(randomIndex)) continue;

        const auto item = ui->listWidget->item(randomIndex);
        const auto itemWidget = dynamic_cast<CardWidget*>(ui->listWidget->itemWidget(item));

        itemWidget->showPromo();
        openedPromos.append(randomIndex);
        fieldSize++;

        const auto promo = generateRandomString(4);
        promos.append(promo);
        addCard(promo);

        break;
    }
}


