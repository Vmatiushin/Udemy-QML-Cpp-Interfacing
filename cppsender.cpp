#include "cppsender.h"
#include <QDebug>

CppSender::CppSender(QObject *parent)
    : QObject{parent}, mTimer(new QTimer(this)),
      mValue(0)
{
    connect(mTimer, &QTimer::timeout,[=](){
        ++mValue;
        emit cppTimer(QString::number(mValue));
    });

    mTimer->start(1000);
}

void CppSender::cppSlot()
{
    emit callQml("Information from C++");
}

