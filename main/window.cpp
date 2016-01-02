#include <QApplication>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QResizeEvent>
#include <QScreen>
#include <QSize>
#include <QStatusBar>
#include <QVBoxLayout>

#include "main/helper.h"
#include "main/window.h"
#include "page/select/action.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    mainHelper = new MainHelper();
    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_ACTION);

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

    //initSelectActionPage();
    initSelectLanguagePage();

    QScreen *screen = QApplication::primaryScreen();

    QRect workareaSize = screen->availableGeometry();
    mainHelper->mainWindowWidth = workareaSize.width();
    mainHelper->mainWindowHeight = workareaSize.height();
    resize(mainHelper->mainWindowWidth, mainHelper->mainWindowHeight);
}

void MainWindow::initSelectActionPage() {
    selectActionPage = new SelectActionPage();
    selectActionPage->prepareUiElements(mainHelper);
    setCentralWidget(selectActionPage);

    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_ACTION);
}

void MainWindow::initSelectLanguagePage() {
    selectLanguagePage = new SelectLanguagePage();
    selectLanguagePage->prepareUiElements(mainHelper);
    setCentralWidget(selectLanguagePage);

    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_LANGUAGE);
}

void MainWindow::resizeUiElements() {

    switch (mainHelper->getCurrentPage()) {

        case MainHelper::PAGE_SELECT_ACTION:
            selectActionPage->resizeUiElements(mainHelper);

        case MainHelper::PAGE_SELECT_LANGUAGE:
            selectLanguagePage->resizeUiElements(mainHelper);
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {

    QSize newSize = event->size();
    mainHelper->mainWindowWidth = newSize.width();
    mainHelper->mainWindowHeight = newSize.height();

    QScreen *screen = QApplication::primaryScreen();
    QRect displaySize = screen->virtualGeometry();
    mainHelper->displayWidth = displaySize.width();
    mainHelper->displayHeight = displaySize.height();

    resizeUiElements();
}
