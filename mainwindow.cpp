#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TransactionDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    model(nullptr), view(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");
    setMinimumSize(500, 400);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Finances.sqlite");
    if (!db.open())
        qFatal("Failed to connect to database.");

    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS categories ("
                    "id INTEGER PRIMARY KEY,"
                    "name TEXT"
                    ")"))
        qFatal("Cannot create or open a table in the database");

    if (!query.exec("CREATE TABLE IF NOT EXISTS transactions ("
                    "id INTEGER PRIMARY KEY,"
                    "category_id INTEGER NOT NULL,"
                    "description TEXT,"
                    "sum INTEGER,"
                    "transaction_date DATE,"
                    "FOREIGN KEY(category_id) REFERENCES categories(id)"
                    ")"))
        qFatal("Cannot create or open a table in the database: ");

    model = new QSqlRelationalTableModel(this, db);
    model->setTable("transactions");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(1, QSqlRelation("categories", "id", "name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Category"));
    model->setHeaderData(2, Qt::Horizontal, tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, tr("Sum"));
    model->setHeaderData(4, Qt::Horizontal, tr("Transaction Date"));
    model->select();

    view = new QTableView(this);
    view->setModel(model);
    view->hideColumn(0);
    view->setItemDelegate(new QSqlRelationalDelegate(view));
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAdd_transaction_triggered()
{
    TransactionDialog *transactionDialog = new TransactionDialog(this);
    connect(transactionDialog, SIGNAL(okButtonClickedSignal()), this, SLOT(addTransactionToDatabase()));
    transactionDialog->exec();
}

void MainWindow::addTransactionToDatabase()
{

}
