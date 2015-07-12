#ifndef CATEGORIESVIEW_H
#define CATEGORIESVIEW_H

#include <QWidget>
#include <QtSql>
#include "AddCategoryDialog.h"

namespace Ui {
class CategoriesView;
}

class CategoriesView : public QWidget
{
    Q_OBJECT

public:
    CategoriesView(QSqlTableModel *model, QWidget *parent = 0);
    ~CategoriesView();

signals:
    void acceptedSignal(QString);

private slots:
    void on_buttonAddCategory_clicked();

    void acceptedSlot(QString);
private:
    Ui::CategoriesView *ui;
    AddCategoryDialog *dialog;
};

#endif // CATEGORIESVIEW_H
