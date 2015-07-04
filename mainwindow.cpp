#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TransactionDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    categoriesModel(nullptr), categoriesView(nullptr),
    transactionsModel(nullptr), transactionsView(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");

    centralArea = new QStackedWidget(this);
    setCentralWidget(centralArea);

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

    categoriesModel = new QSqlTableModel(this, db);
    categoriesModel->setTable("categories");
    categoriesModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    categoriesModel->select();

    categoriesView = new QTableView(centralArea);
    categoriesView->setModel(categoriesModel);
    categoriesView->hideColumn(0);
    centralArea->addWidget(categoriesView);

    transactionsModel = new QSqlRelationalTableModel(this, db);
    transactionsModel->setTable("transactions");
    transactionsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    transactionsModel->setRelation(1, QSqlRelation("categories", "id", "name"));
    transactionsModel->select();

    transactionsView = new QTableView(centralArea);
    transactionsView->setModel(transactionsModel);
    transactionsView->hideColumn(0);
    transactionsView->setItemDelegate(new QSqlRelationalDelegate(transactionsView));
    centralArea->addWidget(transactionsView);
    centralArea->setCurrentWidget(transactionsView);

    //setCentralWidget(categoriesView);
    //view->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch); // Not supported by Qt 4.8
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

void MainWindow::on_actionView_transactions_triggered()
{
    centralArea->setCurrentWidget(transactionsView);
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

void MainWindow::on_actionViewCategories_triggered()
{
    centralArea->setCurrentWidget(categoriesView);
}
