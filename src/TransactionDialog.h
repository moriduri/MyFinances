#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>

namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionDialog(QWidget *parent = 0);
    ~TransactionDialog();

signals:
    void acceptedSignal();

private slots:
    void acceptedSlot();

private:
    Ui::TransactionDialog *ui;
};

#endif // TRANSACTIONDIALOG_H