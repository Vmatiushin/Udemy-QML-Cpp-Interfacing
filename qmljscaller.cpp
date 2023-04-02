#include "qmljscaller.h"
#include "qvariant.h"
#include <QDebug>

QmlJsCaller::QmlJsCaller(QObject *parent)
    : QObject{parent}
{

}

void QmlJsCaller::cppMethod(QString parameter)
{
    qDebug() << "This is C++ talking, calling QML Javascript function";
    callJSMethod(parameter);
}

void QmlJsCaller::setQmlRootObject(QObject *newQmlRootObject)
{
    qmlRootObject = newQmlRootObject;
}

void QmlJsCaller::callJSMethod(QString param)
{
    QVariant returnedValue;
    QVariant cppParameter = QVariant::fromValue(param);

    QMetaObject::invokeMethod(qmlRootObject, "qmlJSFunction",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, cppParameter));

    qDebug() << "C++ is talking, done calling QML JavaScript, the return value is :"
             << returnedValue.toString();
}
