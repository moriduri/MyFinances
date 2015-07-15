#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include "AddDialog.h"
#include <QLineEdit>

class AddCategoryDialog : public AddDialog
{
    Q_OBJECT
public:
    explicit AddCategoryDialog(QWidget *parent = 0);
    ~AddCategoryDialog();

signals:
    void acceptedSignal(QString);

private slots:
    void accepted();
    void onTextChanged(QString);

private:
    QLineEdit *nameLineEdit;
};

#endif // ADDCATEGORYDIALOG_H
