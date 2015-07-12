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

    dialog = new Dialog(Dialog::Category);

    connect(dialog, SIGNAL(acceptedSignal()), this, SLOT(acceptedSlot()));
}

CategoriesView::~CategoriesView()
{
    delete ui;
}

void CategoriesView::on_buttonAddCategory_clicked()
{
    dialog->exec();
}

void CategoriesView::acceptedSlot()
{
    emit acceptedSignal();
}
