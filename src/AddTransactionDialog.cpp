#include "AddTransactionDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QMessageBox>
#include <QPushButton>

AddTransactionDialog::AddTransactionDialog(QWidget *parent) : AddDialog(parent)
{
    QVBoxLayout *labelsLayout = new QVBoxLayout, *lineEditsLayout = new QVBoxLayout;

    QComboBox *comboBox = new QComboBox;
    //while (query.next()) comboBox->addItem(query.value(0).toString()); //add categories to comboBox
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

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addLayout(labelsLayout);
    horizontalLayout->addLayout(lineEditsLayout);

    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    verticalLayout->insertLayout(0, horizontalLayout);    
}


AddTransactionDialog::~AddTransactionDialog()
{
}
