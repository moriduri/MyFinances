#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QStackedWidget>
#include <QTableView>

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
    void on_actionAdd_transaction_triggered();
    void addTransactionToDatabase();

    void on_actionViewCategories_triggered();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    Ui::MainWindow *ui;

    QStackedWidget *centralArea;

    QSqlDatabase db;
    QSqlTableModel *categoriesModel;
    QTableView *categoriesView;
    QSqlRelationalTableModel *transactionsModel;
    QTableView *transactionsView;
};

#endif // MAINWINDOW_H
