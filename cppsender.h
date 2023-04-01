#ifndef CPPSENDER_H
#define CPPSENDER_H

#include <QObject>
#include <QTimer>

class CppSender : public QObject
{
    Q_OBJECT
public:
    explicit CppSender(QObject *parent = nullptr);

signals:
    void callQml(QString parameter);
    void cppTimer(QString value);

public slots:
    void cppSlot();

private:
    QTimer * mTimer;
    int mValue;

};

#endif // CPPSENDER_H
