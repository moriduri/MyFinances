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
}

TransactionsView::~TransactionsView()
{
    delete ui;
}

const TransactionDialog *TransactionsView::getTransactionDialog() const
{
    return transactionDialog;
}

void TransactionsView::on_buttonAddTransaction_clicked()
{
    transactionDialog->exec();
}
