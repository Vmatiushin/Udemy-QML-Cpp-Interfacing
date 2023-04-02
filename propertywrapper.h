#ifndef PROPERTYWRAPPER_H
#define PROPERTYWRAPPER_H

#include <QObject>
#include <QTimer>

class PropertyWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
public:
    explicit PropertyWrapper(QObject *parent = nullptr);

    QString firstname() const;
    void setFirstname(const QString &newFirstname);

    QString lastname() const;
    void setLastname(const QString &newLastname);

signals:

    void firstnameChanged();
    void lastnameChanged();

private:
    QString m_firstname;
    QString m_lastname;

    QTimer * m_timer;
    int m_random_number;
};

#endif // PROPERTYWRAPPER_H
