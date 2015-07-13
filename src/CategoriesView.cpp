#include "CategoriesView.h"
#include "ui_CategoriesView.h"

CategoriesView::CategoriesView(QSqlTableModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CategoriesView)
{
    ui->setupUi(this);

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0);
    ui->tableView->verticalHeader()->hide(); //hides the left vertical header

    dialog = new AddCategoryDialog(this);

    connect(dialog, SIGNAL(acceptedSignal(QString)), SIGNAL(acceptedSignal(QString)));
}

CategoriesView::~CategoriesView()
{
    delete ui;
}

void CategoriesView::on_buttonAddCategory_clicked()
{
    dialog->exec();
}
