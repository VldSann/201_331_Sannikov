#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include "crypto.h"

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CardWidget(QString pinCode, const QString promo, QWidget *parent = nullptr);
  ~CardWidget();

  QString promo = "";
  QString pinCode;
  void showPromo();

 private:
  Ui::CardWidget *ui;
};

#endif  // CARDWIDGET_H
