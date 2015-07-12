#include "AddDialog.h"
#include "ui_Dialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");

    //connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptedSlot()));
}

AddDialog::~AddDialog()
{
    delete ui;
}

/*void AddDialog::acceptedSlot()
{
    emit acceptedSignal();
    close();
}*/
