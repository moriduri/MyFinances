#include "TransactionsView.h"
#include "ui_TransactionsView.h"
#include "TransactionDialog.h"

TransactionsView::TransactionsView(QSqlRelationalTableModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionsView)
{
    ui->setupUi(this);

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    transactionDialog = new TransactionDialog(this);

    connect(transactionDialog, SIGNAL(acceptedSignal()), this, SLOT(acceptedSlot()));
}

TransactionsView::~TransactionsView()
{
    delete ui;
}

void TransactionsView::on_buttonAddTransaction_clicked()
{
    transactionDialog->exec();
}

void TransactionsView::acceptedSlot()
{
    emit acceptedSignal();
}
