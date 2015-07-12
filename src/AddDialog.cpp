#include "AddDialog.h"
#include "ui_Dialog.h"
#include <QSpacerItem>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");
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
