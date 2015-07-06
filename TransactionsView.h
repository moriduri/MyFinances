#ifndef TRANSACTIONSVIEW_H
#define TRANSACTIONSVIEW_H

#include <QWidget>
#include <QtSql>
#include "TransactionDialog.h"

namespace Ui {
class TransactionsView;
}

class TransactionsView : public QWidget
{
    Q_OBJECT

public:
    TransactionsView(QSqlRelationalTableModel *model, QWidget *parent = 0);
    ~TransactionsView();

    const TransactionDialog *getTransactionDialog() const;

private slots:
    void on_buttonAddTransaction_clicked();

private:
    Ui::TransactionsView *ui;
    TransactionDialog *transactionDialog;
};

#endif // TRANSACTIONSVIEW_H
