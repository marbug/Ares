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

void MainWindow::prepareMainWindow() {
    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    osName = "Linux";
    menuBar()->setNativeMenuBar(false);
#endif

    startButton = new QPushButton("Start", this);
    editButton = new QPushButton("Edit", this);
    statusBarLabel = new QPushButton("", this);
    statusBarLabel->setObjectName("statusBarLabel");

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
    int labelHeight;

    QScreen *screen = QApplication::primaryScreen();
    QRect displaySize = screen->virtualGeometry();

    statusBarLabel->setText(
        "Size: " + QString::number(mainWindowWidth) + "x" + QString::number(mainWindowHeight) +
        " (" + QString::number(displaySize.width()) + "x" + QString::number(displaySize.height()) + ")\nBuild " +
        __TIME__ + " " + osName
    );

    startButton->setContentsMargins(0, 0, 0, 0);
    editButton->setContentsMargins(0, 0, 0, 0);
    statusBarLabel->setContentsMargins(0, 0, 0, 0);

    labelHeight = mainWindowWidth / MAIN_WINDOW_PARTS;
    if (labelHeight < STATUS_BAR_MIN_HEIGHT) {
        labelHeight = STATUS_BAR_MIN_HEIGHT;
    }

    if ((mainWindowHeight - labelHeight) >= mainWindowWidth * 3 / 4) {
        int margin = mainWindowWidth / MAIN_WINDOW_PARTS;
        int buttonWidth = mainWindowWidth - margin * 2;
        int buttonHeight = (mainWindowHeight - labelHeight - margin * 3) / 2;

        startButton->setGeometry(margin, margin, buttonWidth, buttonHeight);

        editButton->setGeometry(margin, margin * 2 + buttonHeight, buttonWidth, buttonHeight);
    }
    else {
        int margin = (mainWindowHeight - labelHeight) / MAIN_WINDOW_PARTS;
        int buttonWidth = (mainWindowWidth - margin * 3) / 2;
        int buttonHeight = (mainWindowHeight - labelHeight) - margin * 2;

        startButton->setGeometry(margin, margin, buttonWidth, buttonHeight);

        editButton->setGeometry(buttonWidth + margin * 2, margin, buttonWidth, buttonHeight);
    }

    statusBarLabel->setGeometry(0, mainWindowHeight - labelHeight, mainWindowWidth, labelHeight);
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QSize newSize = event->size();

    mainWindowWidth = newSize.width();
    mainWindowHeight = newSize.height();

    resizeUiElements();
}
