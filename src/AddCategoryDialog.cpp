#include "AddCategoryDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

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
}

AddCategoryDialog::~AddCategoryDialog()
{
}

void AddCategoryDialog::accepted()
{
    emit acceptedSignal(nameLineEdit->text());
}
