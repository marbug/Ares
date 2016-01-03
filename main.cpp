#include "mainWindow.h"
#include "stylesheet.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setStyleSheet(DEFAULT_STYLE_SHEET);

    MainWindow mw;
    mw.show();

    return app.exec();
}
