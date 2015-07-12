#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include "AddDialog.h"

class AddCategoryDialog : public AddDialog
{
    Q_OBJECT
public:
    explicit AddCategoryDialog(QWidget *parent = 0);
    ~AddCategoryDialog();
};

#endif // ADDCATEGORYDIALOG_H
