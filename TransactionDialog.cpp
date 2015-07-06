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
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(okButtonClicked())); //clicked OK
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close())); //clicked CANCEL
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}

void TransactionDialog::okButtonClicked()
{
    //  TODO: Add signal connection instead of this [MORIDURI: I think that's already a good implementation]
    emit okButtonClickedSignal();
    close();
}
