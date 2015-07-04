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
    connect(ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(okButtonClicked()));
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}

void TransactionDialog::okButtonClicked()
{
    //  TODO: Add signal connection instead of this
    emit okButtonClickedSignal();
}
