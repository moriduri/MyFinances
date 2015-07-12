#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QtSql>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(const int type, QWidget *parent = 0);
    ~Dialog();
    enum type {Transaction, Category};

signals:
    void acceptedSignal(); //TODO transaction signal with multiple qstrings as arguments (category, description, date, sum)
    void acceptedSignal(QString);

private slots:
    void acceptedSlot();
    void onTextChanged(QString);

private:
    Ui::Dialog *ui;
    QSqlDatabase db;
    int dialogType;
    void transaction();
    void category();
};

#endif // DIALOG_H
