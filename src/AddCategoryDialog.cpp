#include "AddCategoryDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

AddCategoryDialog::AddCategoryDialog(QWidget *parent) : AddDialog(parent)
{
    QVBoxLayout *labelsLayout = new QVBoxLayout;
    labelsLayout->addWidget(new QLabel(tr("Name")));

    QVBoxLayout *lineEditsLayout = new QVBoxLayout;
    lineEditsLayout->addWidget(new QLineEdit);

    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addLayout(labelsLayout);
    horizontalLayout->addLayout(lineEditsLayout);

    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    verticalLayout->insertLayout(0, horizontalLayout);
}

AddCategoryDialog::~AddCategoryDialog()
{
}
