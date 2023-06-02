#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/CountDown.h"
#include "src/MusicPlayer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/countdown-qml/qml/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    CountDown countDown;
    engine.rootContext()->setContextProperty("countDown", &countDown);

    MusicPlayer musicPlayer(countDown);
    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);

    engine.load(url);

    return app.exec();
}
