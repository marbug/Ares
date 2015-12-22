#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QScreen>
#include <QSize>
#include <QStatusBar>
#include <QVBoxLayout>

QString MAIN_WINDOW_TITLE = "Ares";
int MAIN_WINDOW_MIN_WIDTH = 240;
int MAIN_WINDOW_MIN_HEIGHT = 240;
bool isPortraitLayout;
int mainWindowWidth;
int mainWindowHeight;
QString osName = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    osName = "Linux";
    menuBar()->setNativeMenuBar(false);
#endif

    setMinimumWidth(MAIN_WINDOW_MIN_WIDTH);
    setMinimumHeight(MAIN_WINDOW_MIN_HEIGHT);

    setWindowTitle(MAIN_WINDOW_TITLE);

    QScreen *screen = QApplication::primaryScreen();
    isPortraitLayout = screen->isPortrait(screen->orientation());

    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    QRect workareaSize = screen->availableGeometry();
    QRect displaySize = screen->virtualGeometry();
    mainWindowWidth = workareaSize.width();
    mainWindowHeight = workareaSize.height();
    resize(mainWindowWidth, mainWindowHeight);

    QLabel *label = new QLabel(
        "Size: " + QString::number(mainWindowWidth) + "x" + QString::number(mainWindowHeight) +
        " (" + QString::number(displaySize.width()) + "x" + QString::number(displaySize.height()) + ") " + osName
    );
    statusBar->addWidget(label);

    if (isPortraitLayout) {
        int margin = mainWindowWidth / 16;
        int buttonWidth = mainWindowWidth - margin * 2;
        int buttonHeight = (mainWindowHeight - margin * 3) / 2;

        QPushButton *startButton = new QPushButton("Start", this);
        startButton->setContentsMargins(0, 0, 0, 0);
        startButton->setGeometry(QRect(QPoint(margin, margin), QSize(buttonWidth, buttonHeight)));

        QPushButton *editButton = new QPushButton("Edit", this);
        editButton->setContentsMargins(0, 0, 0, 0);
        editButton->setGeometry(QRect(QPoint(margin, margin * 2 + buttonHeight), QSize(buttonWidth, buttonHeight)));
    }
    else {
        int margin = mainWindowHeight / 16;
        int buttonWidth = mainWindowWidth / 2 - margin * 3;
        int buttonHeight = mainWindowHeight - margin * 4;

        QPushButton *startButton = new QPushButton("Start", this);
        startButton->setGeometry(QRect(QPoint(margin * 2, margin * 2), QSize(buttonWidth, buttonHeight)));

        QPushButton *editButton = new QPushButton("Edit", this);
        editButton->setGeometry(QRect(QPoint(buttonWidth + margin * 4, margin * 2), QSize(buttonWidth, buttonHeight)));
    }
}

MainWindow::~MainWindow()
{

}
