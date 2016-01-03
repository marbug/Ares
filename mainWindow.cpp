#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QResizeEvent>
#include <QScreen>
#include <QSize>
#include <QStatusBar>
#include <QVBoxLayout>

#include "mainHelper.h"
#include "mainWindow.h"
#include "page/selectActionPage.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    mainHelper = new MainHelper();

    pageHelper = new PageHelper(this, mainHelper);

    prepareMainWindow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::prepareMainWindow() {

    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    menuBar()->setNativeMenuBar(false);
#endif

    setMinimumWidth(MAIN_WINDOW_MIN_WIDTH);
    setMinimumHeight(MAIN_WINDOW_MIN_HEIGHT);

    setWindowTitle(MAIN_WINDOW_TITLE);

    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_LANGUAGE);

    QScreen *screen = QApplication::primaryScreen();

    QRect workareaSize = screen->availableGeometry();
    mainHelper->mainWindowWidth = workareaSize.width();
    mainHelper->mainWindowHeight = workareaSize.height();
    resize(mainHelper->mainWindowWidth, mainHelper->mainWindowHeight);
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QSize newSize = event->size();
    mainHelper->mainWindowWidth = newSize.width();
    mainHelper->mainWindowHeight = newSize.height();

    QScreen *screen = QApplication::primaryScreen();
    QRect displaySize = screen->virtualGeometry();
    mainHelper->displayWidth = displaySize.width();
    mainHelper->displayHeight = displaySize.height();

    pageHelper->resizeUiElements();
}
