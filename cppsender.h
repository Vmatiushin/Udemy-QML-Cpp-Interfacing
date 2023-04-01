#ifndef CPPSENDER_H
#define CPPSENDER_H

#include <QObject>

class CppSender : public QObject
{
    Q_OBJECT
public:
    explicit CppSender(QObject *parent = nullptr);

    Q_INVOKABLE void consoleLog();

    Q_INVOKABLE QString buttonTextChange(QString parameter);

signals:

};

#endif // CPPSENDER_H
