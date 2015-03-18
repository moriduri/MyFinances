#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>

class Category : public QObject
{
    Q_OBJECT
private:
    QString m_name;
    const Category *m_parent;
public:
    Category(const QString &name, const Category *parent = 0);
    ~Category();
};

#endif // CATEGORY_H
