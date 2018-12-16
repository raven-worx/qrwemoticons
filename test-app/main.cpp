#include <QApplication>
#include <Mainwindow.h>

int main(int argc, char *argv[])
{
    qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));

    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
