#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "fieldmanager.h"
#include <QQuickWindow>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
    {return -1;}

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    FieldManager* fieldManager = new FieldManager(window);
    srand(time(NULL)); //initialize random seed for building creation
    QObject::connect(fieldManager, SIGNAL(updateGraphics()), window, SLOT(onUpdateGraphics()));
    QObject::connect(fieldManager, SIGNAL(actionPerformed()), window, SLOT(onActionPerformed()));
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("fieldManager", fieldManager);
        //all objects in context are accessible from QT
    fieldManager->newGame();
    fieldManager->updateGraphics();
    return app.exec();
}
