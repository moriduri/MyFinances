#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
    void acceptedSignal();

private slots:
    void acceptedSlot();

private:
    Ui::Dialog *ui;
    void transaction();
    void category();
};

#endif // DIALOG_H
