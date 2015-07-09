#include "TransactionDialog.h"
#include "ui_TransactionDialog.h"
#include <QPushButton>

TransactionDialog::TransactionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");
    ui->dateEdit->setDate(QDate::currentDate());
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptedSlot())); //clicked OK
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close())); //clicked CANCEL
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}

void TransactionDialog::acceptedSlot()
{
    emit acceptedSignal();
    close();
}
