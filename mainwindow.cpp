#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TransactionDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Finances.sqlite");
    if (!db.open())
        qFatal("Failed to connect to database.");

    QSqlQuery query(db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS categories ("
                    "id INTEGER PRIMARY KEY,"
                    "description TEXT"
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
}
