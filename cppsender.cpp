#include "cppsender.h"
#include <QDebug>

CppSender::CppSender(QObject *parent)
    : QObject{parent}
{

}

void CppSender::consoleLog()
{
    qDebug() << "Jija was activated!";
}

QString CppSender::buttonTextChange(QString parameter)
{
    return parameter;
}
