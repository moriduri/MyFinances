#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
    void acceptedSignal();

private slots:
    void acceptedSlot();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
