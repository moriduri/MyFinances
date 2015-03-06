#include "TransactionDialog.h"
#include "ui_TransactionDialog.h"

TransactionDialog::TransactionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}
