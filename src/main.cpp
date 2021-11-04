#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickWindow>
#include <QQmlProperty>
#include <QQmlContext>

#include "impact.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<Impact>("Impact", 1, 0, "Impact");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(QUrl("qrc:/qml/FloatingButton.qml"));
    engine.load(QUrl("qrc:/qml/FloatingCooldown.qml"));

    engine.load(url);

    QObject *mainWindowObj = engine.rootObjects().last();

    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("PARENT_OBJ", mainWindowObj);

    return app.exec();
}
