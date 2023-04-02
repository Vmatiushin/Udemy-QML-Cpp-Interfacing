#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "qmljscaller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QmlJsCaller jsCaller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("QmlJsCaller", &jsCaller);
    const QUrl url(u"qrc:/Udemy_QML_Cpp_Interfacing_ContextProperty/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    jsCaller.setQmlRootObject(engine.rootObjects().first());

    return app.exec();
}
