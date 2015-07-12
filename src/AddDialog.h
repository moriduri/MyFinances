#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_Dialog.h"

namespace Ui {
    class Dialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

signals:
    //void acceptedSignal();

private slots:
    //void acceptedSlot();

protected:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
