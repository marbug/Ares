#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <string>

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:

        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:

        const int MAIN_WINDOW_MIN_WIDTH = 240;
        const int MAIN_WINDOW_MIN_HEIGHT = 240;
        const int MAIN_WINDOW_PARTS = 10;
        const QString MAIN_WINDOW_TITLE = "Ares";

        const int STATUS_BAR_MIN_HEIGHT = 60;

        QPushButton *editButton;
        QLabel mainWindowLabel;
        int mainWindowHeight;
        int mainWindowWidth;
        QString osName = "";
        QPushButton *startButton;
        QPushButton *statusBarLabel;

        void prepareMainWindow();
        void resizeUiElements();
        void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
