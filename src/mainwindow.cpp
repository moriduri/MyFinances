#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    categoriesModel(nullptr), categoriesView(nullptr),
    transactionsModel(nullptr), transactionsView(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("MyFinance");
    setMinimumSize(600, 400); //ensures that the header sections are displayed correctly

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
    categoriesModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
    categoriesModel->select();

    categoriesView = new CategoriesView(categoriesModel, centralArea);
    connect(categoriesView, SIGNAL(acceptedSignal(QString)), this, SLOT(addCategoryToDatabase(QString)));
    centralArea->addWidget(categoriesView);

    transactionsModel = new QSqlRelationalTableModel(this, db);
    transactionsModel->setTable("transactions");
    transactionsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    transactionsModel->setRelation(1, QSqlRelation("categories", "id", "name"));
    transactionsModel->setHeaderData(1, Qt::Horizontal, tr("Category")); //formats the sections label
    transactionsModel->setHeaderData(2, Qt::Horizontal, tr("Description"));
    transactionsModel->setHeaderData(3, Qt::Horizontal, tr("Sum"));
    transactionsModel->setHeaderData(4, Qt::Horizontal, tr("Transaction Date"));
    transactionsModel->select();

    // This actually will evolve in a much prettier view
    transactionsView = new TransactionsView(transactionsModel, centralArea);
    connect(transactionsView, SIGNAL(acceptedSignal()), this, SLOT(addTransactionToDatabase()));
    centralArea->addWidget(transactionsView);
    centralArea->setCurrentWidget(transactionsView);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

/*void MainWindow::resizeEvent(QResizeEvent *event) { //custom resizeEvent handler
    QTableView *TableView = dynamic_cast<QTableView *>(centralArea->currentWidget()); //TableView points to the current displayed table
    int columnCount = (TableView->model()->columnCount() - 1);
    for (int i=1; i<=columnCount; i++) {
        if (i != columnCount) {
            TableView->setColumnWidth(i, this->width()/columnCount); //stretchs the sections of the current displayed table (supports Qt v4.8)
        } else {
            TableView->setColumnWidth(i, (this->width()/columnCount - 2)); //avoids the appearance of the horizontal scrollbar
        }
    }
    TableView->horizontalHeader()->setMinimumSectionSize(this->width()/columnCount);
}*/

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionView_transactions_triggered()
{
    centralArea->setCurrentWidget(transactionsView);
    //resizeEvent(nullptr); //triggers the resize event
}


void MainWindow::addTransactionToDatabase()
{
    //  TODO: Addition to database (change signal/slot prototype and add to model)
}

void MainWindow::on_actionViewCategories_triggered()
{
    centralArea->setCurrentWidget(categoriesView);
    //resizeEvent(nullptr);
}

void MainWindow::addCategoryToDatabase(QString name)
{
    int id = categoriesModel->rowCount();
    categoriesModel->insertRow(id);
    categoriesModel->setData(categoriesModel->index(id, 0), id);
    categoriesModel->setData(categoriesModel->index(id, 1), name);
    categoriesModel->submitAll();
}
