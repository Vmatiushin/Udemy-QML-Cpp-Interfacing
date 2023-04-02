#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "propertywrapper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    PropertyWrapper wrapper;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextObject(&wrapper);
    const QUrl url(u"qrc:/Udemy_QML_Cpp_Interfacing_ContextProperty/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
