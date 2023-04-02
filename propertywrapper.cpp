#include "propertywrapper.h"

#include <stdlib.h>
#include <time.h>

PropertyWrapper::PropertyWrapper(QObject *parent)
    : QObject{parent},
      m_firstname("Тюшенька"),
      m_lastname("МОЯ"),
      m_timer(new QTimer(this)),
      m_random_number(0)
{
    srand(time(NULL));

    QStringList list;
    list << "Лапочка" << "Мышка-Норушка" << "Еврейчик предлагающий дельце ;3" << "Гузлинка" << "Хитрая жижечка" << "Сладкая лапочка" << "Жирик!" << "Масенька" << "Пусье-монпансье" << "Булоцька!!" << "Чудосье";

    connect(m_timer, &QTimer::timeout,[=](){
        m_random_number = rand() % (list.size());
        setLastname(list[m_random_number]);
    });

    m_timer->start(1000);
}

QString PropertyWrapper::firstname() const
{
    return m_firstname;
}

void PropertyWrapper::setFirstname(const QString &newFirstname)
{
    if (m_firstname == newFirstname)
        return;
    m_firstname = newFirstname;
    emit firstnameChanged();
}

QString PropertyWrapper::lastname() const
{
    return m_lastname;
}

void PropertyWrapper::setLastname(const QString &newLastname)
{
    if (m_lastname == newLastname)
        return;
    m_lastname = newLastname;
    emit lastnameChanged();
}
