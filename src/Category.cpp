#include "Category.h"

Category::Category(const QString &name, const Category *parent) :
    m_name(name), m_parent(parent)
{
}

Category::~Category()
{
}
