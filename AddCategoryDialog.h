#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class AddCategoryDialog;
}

class AddCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategoryDialog(QWidget *parent = 0);
    ~AddCategoryDialog();

signals:
    void acceptedSignal();

private slots:
    void acceptedSlot();

private:
    Ui::AddCategoryDialog *ui;
};

#endif // ADDCATEGORYDIALOG_H
