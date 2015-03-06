#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include <QDate>

class Transaction : public QObject
{
    Q_OBJECT
private:
    QString description;
    int sum;
    QDate date;
public:
    Transaction();
    ~Transaction();
};

#endif // TRANSACTION_H
