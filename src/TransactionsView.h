#ifndef TRANSACTIONSVIEW_H
#define TRANSACTIONSVIEW_H

#include <QWidget>
#include <QtSql>
#include "Dialog.h"

namespace Ui {
    class TransactionsView;
}

class TransactionsView : public QWidget
{
    Q_OBJECT

public:
    TransactionsView(QSqlRelationalTableModel *model, QWidget *parent = 0);
    ~TransactionsView();

signals:
    void acceptedSignal();

private slots:
    void on_buttonAddTransaction_clicked();
    void acceptedSlot();

private:
    Ui::TransactionsView *ui;
    Dialog *dialog;
};

#endif // TRANSACTIONSVIEW_H
