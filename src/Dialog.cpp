#include "Dialog.h"
#include "ui_Dialog.h"
#include <QSpacerItem>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

Dialog::Dialog(const int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");

    if (type == Transaction) transaction();
    else if (type == Category) category();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::transaction()
{
    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    QVBoxLayout *labelsLayout = new QVBoxLayout, *lineEditsLayout = new QVBoxLayout;
    QComboBox *comboBox = new QComboBox;
    labelsLayout->addWidget(new QLabel(tr("Category")));
    lineEditsLayout->addWidget(comboBox);
    QLineEdit *Description = new QLineEdit;
    labelsLayout->addWidget(new QLabel(tr("Description")));
    lineEditsLayout->addWidget(Description);
    QDateEdit *Date = new QDateEdit;
    Date->setDate(QDate::currentDate());
    labelsLayout->addWidget(new QLabel(tr("Date")));
    lineEditsLayout->addWidget(Date);
    QLineEdit *Sum = new QLineEdit;
    labelsLayout->addWidget(new QLabel(tr("Sum")));
    lineEditsLayout->addWidget(Sum);
    horizontalLayout->addLayout(labelsLayout);
    horizontalLayout->addLayout(lineEditsLayout);
    verticalLayout->insertLayout(0, horizontalLayout);
}

void Dialog::category()
{
    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    QVBoxLayout *labelsLayout = new QVBoxLayout, *lineEditsLayout = new QVBoxLayout;
    QLineEdit *Name = new QLineEdit;
    labelsLayout->addWidget(new QLabel(tr("Name")));
    lineEditsLayout->addWidget(Name);
    horizontalLayout->addLayout(labelsLayout);
    horizontalLayout->addLayout(lineEditsLayout);
    verticalLayout->insertLayout(0, horizontalLayout);
}

void Dialog::acceptedSlot()
{
    emit acceptedSignal();
    close();
}
