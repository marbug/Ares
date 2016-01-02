#ifndef SELECTACTIONPAGE_H
#define SELECTACTIONPAGE_H

#include "mainhelper.h"
#include <QPushButton>

class SelectActionPage : public QWidget {

    private:

        const int MAIN_WINDOW_PARTS = 10;
        const int STATUS_BAR_MIN_HEIGHT = 60;

        QPushButton *editButton;
        QPushButton *startButton;
        QPushButton *statusBarLabel;

    public:

        SelectActionPage();
        ~SelectActionPage();

        void prepareUiElements(MainHelper *mainHelper);
        void resizeUiElements(MainHelper *mainHelper);
};

#endif // SELECTACTIONPAGE_H
