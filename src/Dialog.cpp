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
#include <QMessageBox>
#include <QPushButton>

Dialog::Dialog(const int type, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Finances.sqlite");
    if (!db.open())
        qFatal("Failed to connect to database.");

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(acceptedSlot())); //OK clicked
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(close())); //CANCEL clicked

    if (type == Transaction) {
        dialogType = Transaction;
        transaction();
    } else if (type == Category) {
        dialogType = Category;
        category();
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::transaction()
{
    QSqlQuery query(db);
    if (!query.exec("SELECT name FROM categories"))
        qFatal("Cannot select data from the categories table");
    QVBoxLayout *verticalLayout = dynamic_cast<QVBoxLayout *>(layout());
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    QVBoxLayout *labelsLayout = new QVBoxLayout, *lineEditsLayout = new QVBoxLayout;
    QComboBox *comboBox = new QComboBox;
    while (query.next()) comboBox->addItem(query.value(0).toString()); //add categories to comboBox
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

    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
    connect(Name, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
}

void Dialog::acceptedSlot()
{
    if (dialogType == Transaction) emit acceptedSignal(); //TODO transaction signal with multiple qstrings as arguments (category, description, date, sum)
    else if (dialogType == Category) emit acceptedSignal(findChildren<QLineEdit *>()[0]->text());
}

void Dialog::onTextChanged(QString Text)
{
    if (Text.compare("") != 0) ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(true);
    else ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
}
