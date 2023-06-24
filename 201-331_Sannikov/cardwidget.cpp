#include "cardwidget.h"

#include "ui_cardwidget.h"

CardWidget::CardWidget(QString pinCode, const QString promo, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);

  ui->promoButton->setText("");
  this->promo = promo;
  this->pinCode = pinCode;
}

CardWidget::~CardWidget() {
  delete ui;
}

void CardWidget::showPromo() {
  QString decrPromo = crypto::decrypt(promo.toUtf8(), pinCode, pinCode);
  ui->promoButton->setText(decrPromo);
}
