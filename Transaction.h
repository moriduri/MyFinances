#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QObject>
#include <QDate>

#include "Category.h"

class Transaction : public QObject
{
    Q_OBJECT
private:
    QString m_description;
    Category m_category;
    int m_sum;
    QDate m_date;
public:
    Transaction();
    ~Transaction();
};

#endif // TRANSACTION_H
