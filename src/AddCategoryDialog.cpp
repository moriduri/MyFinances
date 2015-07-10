#include "AddCategoryDialog.h"
#include "ui_AddCategoryDialog.h"

AddCategoryDialog::AddCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategoryDialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptedSlot())); //clicked OK
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close())); //clicked CANCEL
}

AddCategoryDialog::~AddCategoryDialog()
{
    delete ui;
}

void AddCategoryDialog::acceptedSlot()
{
    emit acceptedSignal();
    close();
}
