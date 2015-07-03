#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTableView>
#include <QHeaderView>

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
    void on_actionAdd_transaction_triggered();
    void addTransactionToDatabase();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlRelationalTableModel *model;
    QTableView *view;
};

#endif // MAINWINDOW_H
