#include "TransactionsView.h"
#include "ui_TransactionsView.h"

TransactionsView::TransactionsView(QSqlRelationalTableModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionsView)
{
    ui->setupUi(this);

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

    dialog = new Dialog(Dialog::Transaction);

    connect(dialog, SIGNAL(acceptedSignal()), this, SLOT(acceptedSlot()));
}

TransactionsView::~TransactionsView()
{
    delete ui;
}

void TransactionsView::on_buttonAddTransaction_clicked()
{
    dialog->exec();
}

void TransactionsView::acceptedSlot()
{
    emit acceptedSignal();
}
