#include <QString>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileInfo>
#include <QDir>
#include <QUrl>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    auto applicationPath = []()
    {
        QString argv0 = QCoreApplication::arguments()[0];

        if (argv0.startsWith(QChar('/'))) {
            // First, try argv[0] if it's an absolute path (needed for booster)
            return argv0;
        } else {
            // If that doesn't give an absolute path, use /proc-based detection
            return QCoreApplication::applicationFilePath();
        }
    };

    auto appName = [applicationPath]() {
        QFileInfo exe = QFileInfo(applicationPath());
        return exe.fileName();
    };

    auto dataDir = [appName, applicationPath]()
    {
        QFileInfo exe = QFileInfo(applicationPath());

        // "/usr/bin/<appname>" --> "/usr/share/<appname>/"
        QString path = exe.absolutePath();
        int i = path.lastIndexOf(QChar('/')) + 1;
        return path.replace(i, path.length() - i, "share/") + appName();
    };

    auto pathToMainQml = [dataDir, appName]()
    {
        return QUrl::fromLocalFile(
                    QDir::cleanPath(dataDir() + "/qml/" +
                                    appName() + ".qml"));
    };

    QQmlApplicationEngine engine;
    const QUrl url(pathToMainQml());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
