#ifndef SELECT_ACTION_PAGE_H
#define SELECT_ACTION_PAGE_H

#include "mainHelper.h"
#include "button/selectPageButton.h"

class SelectActionPage : public QWidget {
private:

    const int MAIN_WINDOW_PARTS = 10;
    const int STATUS_BAR_MIN_HEIGHT = 60;

    SelectPageButton *editButton;
    SelectPageButton *startButton;
    SelectPageButton *statusBarLabel;

    const char* EDIT_BUTTON_NAMES[MainHelper::NUMBER_OF_SUPPORTED_LANGUAGES];
    const char* START_BUTTON_NAMES[MainHelper::NUMBER_OF_SUPPORTED_LANGUAGES];

    void initButtonNames();

public:

    SelectActionPage();
    ~SelectActionPage();

    void prepareUiElements(MainHelper *mainHelper);
    void resizeUiElements(MainHelper *mainHelper);
};

#endif // SELECT_ACTION_PAGE_H
