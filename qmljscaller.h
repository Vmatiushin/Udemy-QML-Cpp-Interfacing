#ifndef QMLJSCALLER_H
#define QMLJSCALLER_H

#include <QObject>

class QmlJsCaller : public QObject
{
    Q_OBJECT
public:
    explicit QmlJsCaller(QObject *parent = nullptr);

    Q_INVOKABLE void cppMethod(QString parameter);

    void setQmlRootObject(QObject *newQmlRootObject);

signals:

public slots:
private:
    void callJSMethod(QString param);
    QObject * qmlRootObject;

};

#endif // QMLJSCALLER_H
