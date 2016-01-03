#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "mainHelper.h"
#include "page/selectActionPage.h"
#include "page/selectLanguagePage.h"

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:

        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:

        const int MAIN_WINDOW_MIN_WIDTH = 240;
        const int MAIN_WINDOW_MIN_HEIGHT = 240;
        const QString MAIN_WINDOW_TITLE = "Ares";

        MainHelper *mainHelper;

        void prepareMainWindow();

        void resizeEvent(QResizeEvent *);
        void resizeUiElements();

        SelectActionPage *selectActionPage;
        void initSelectActionPage();

        SelectLanguagePage *selectLanguagePage;
        void initSelectLanguagePage();
};

#endif // MAINWINDOW_H
