#ifndef EDIT_SETTINGS_PAGE_H
#define EDIT_SETTINGS_PAGE_H

#include "mainHelper.h"
#include "button/selectPageButton.h"

class EditSettingsPage : public QWidget {
private:

    const int NUMBER_OF_PARTS = 10;

    SelectPageButton *backButton;

    const char* BACK_BUTTON_NAMES[MainHelper::NUMBER_OF_SUPPORTED_LANGUAGES];

    void initButtonNames();

public:

    EditSettingsPage();
    ~EditSettingsPage();

    void prepareUiElements(MainHelper *mainHelper);
    void resizeUiElements(MainHelper *mainHelper);
};

#endif // EDIT_SETTINGS_PAGE_H
