#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QResizeEvent>
#include <QScreen>
#include <QSize>
#include <QStatusBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    prepareMainWindow();
    resizeUiElements();
}

MainWindow::~MainWindow()
{

}

void MainWindow::fixIsPortraitLayout() {
    isPortraitLayout = (mainWindowHeight >= mainWindowWidth);
}

void MainWindow::prepareMainWindow() {
    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    osName = "Linux";
    menuBar()->setNativeMenuBar(false);
#endif

    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    statusBarLabel = new QLabel();
    statusBar->addWidget(statusBarLabel);

    startButton = new QPushButton("Start", this);
    editButton = new QPushButton("Edit", this);

    setMinimumWidth(MAIN_WINDOW_MIN_WIDTH);
    setMinimumHeight(MAIN_WINDOW_MIN_HEIGHT);

    setWindowTitle(MAIN_WINDOW_TITLE);

    QScreen *screen = QApplication::primaryScreen();

    QRect workareaSize = screen->availableGeometry();
    mainWindowWidth = workareaSize.width();
    mainWindowHeight = workareaSize.height();
    resize(mainWindowWidth, mainWindowHeight);
}

void MainWindow::resizeUiElements() {
    QScreen *screen = QApplication::primaryScreen();
    QRect displaySize = screen->virtualGeometry();

    statusBarLabel->setText(
        "Size: " + QString::number(mainWindowWidth) + "x" + QString::number(mainWindowHeight) +
        " (" + QString::number(displaySize.width()) + "x" + QString::number(displaySize.height()) + ") build " +
        __TIME__ + " " + osName
    );

    startButton->setContentsMargins(0, 0, 0, 0);
    editButton->setContentsMargins(0, 0, 0, 0);

    if (isPortraitLayout) {
        int margin = mainWindowWidth / 16;
        int buttonWidth = mainWindowWidth - margin * 2;
        int buttonHeight = (mainWindowHeight - margin * 3) / 2;

        startButton->setGeometry(QRect(QPoint(margin, margin), QSize(buttonWidth, buttonHeight)));

        editButton->setGeometry(QRect(QPoint(margin, margin * 2 + buttonHeight), QSize(buttonWidth, buttonHeight)));
    }
    else {
        int margin = mainWindowHeight / 16;
        int buttonWidth = mainWindowWidth / 2 - margin * 3;
        int buttonHeight = mainWindowHeight - margin * 4;

        startButton->setGeometry(QRect(QPoint(margin * 2, margin * 2), QSize(buttonWidth, buttonHeight)));

        editButton->setGeometry(QRect(QPoint(buttonWidth + margin * 4, margin * 2), QSize(buttonWidth, buttonHeight)));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QSize newSize = event->size();

    mainWindowWidth = newSize.width();
    mainWindowHeight = newSize.height();

    fixIsPortraitLayout();

    resizeUiElements();
}
