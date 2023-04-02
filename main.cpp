#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "movie.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Movie movie;
    movie.setTitle("JoJo");
    movie.setMainCharacter("Jonathan J");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("Movie", &movie);
    const QUrl url(u"qrc:/Udemy_QML_Cpp_Interfacing_ContextProperty/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
