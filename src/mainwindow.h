#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QStackedWidget>
#include <QTableView>
#include <QString>
#include "CategoriesView.h"
#include "TransactionsView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionView_transactions_triggered();
    void addTransactionToDatabase();

    void on_actionViewCategories_triggered();
    void addCategoryToDatabase(QString name);

protected:
    //  I don't think we need to care about things like resizing
    //  before we get our UI done (all views written etc.)
    //virtual void resizeEvent(QResizeEvent *);

private:
    Ui::MainWindow *ui;

    QStackedWidget *centralArea;

    QSqlDatabase db;
    QSqlTableModel *categoriesModel;
    CategoriesView *categoriesView;
    QSqlRelationalTableModel *transactionsModel;
    TransactionsView *transactionsView;
};

#endif // MAINWINDOW_H
