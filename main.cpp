#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cppsender.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CppSender sender;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Sender", &sender);
    const QUrl url(u"qrc:/Udemy_QML_Cpp_Interfacing_ContextProperty/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
