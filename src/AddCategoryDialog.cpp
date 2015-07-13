#include "AddCategoryDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

AddCategoryDialog::AddCategoryDialog(QWidget *parent) :
    AddDialog(parent), nameLineEdit(nullptr)
{
    QVBoxLayout *labelsLayout = new QVBoxLayout;
    labelsLayout->addWidget(new QLabel(tr("Name")));

    QVBoxLayout *lineEditsLayout = new QVBoxLayout;
    nameLineEdit = new QLineEdit;
    lineEditsLayout->addWidget(nameLineEdit);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addLayout(labelsLayout);
    horizontalLayout->addLayout(lineEditsLayout);

    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    verticalLayout->insertLayout(0, horizontalLayout);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accepted()));

    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
    connect(nameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
}

AddCategoryDialog::~AddCategoryDialog()
{
}

void AddCategoryDialog::accepted()
{
    emit acceptedSignal(nameLineEdit->text());
}

void AddCategoryDialog::onTextChanged(QString Text)
{
    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(Text.compare("") ? true : false);
}
