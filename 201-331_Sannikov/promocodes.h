#ifndef PROMOCODES_H
#define PROMOCODES_H

#include <QWidget>
#include "cardwidget.h"

namespace Ui {
class promocodes;
}

class promocodes : public QWidget
{
    Q_OBJECT

public:
    explicit promocodes(QWidget *parent = nullptr);
    ~promocodes();
signals:
    void firstWindow();
private slots:
    QString generateRandomString(int);
    void initPromo();
    void addCard(QString promo);
    void on_pushButton_clicked();

private:
    Ui::promocodes *ui;
    QVector<QString> promos;
    uint fieldSize = 9;

};

#endif // PROMOCODES_H
