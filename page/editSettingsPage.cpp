#include "mainHelper.h"
#include "page/editSettingsPage.h"
#include "button/selectPageButton.h"

EditSettingsPage::EditSettingsPage() {
    initButtonNames();
}

EditSettingsPage::~EditSettingsPage() {

}

void EditSettingsPage::initButtonNames() {
    BACK_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_ENGLISH] ="Back";
    BACK_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_RUSSIAN] = "Назад";
    BACK_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_UKRAINIAN] = "Назад";
}

void EditSettingsPage::prepareUiElements(MainHelper *mainHelper) {

    setContentsMargins(0, 0, 0, 0);

    backButton = new SelectPageButton("Edit", this, MainHelper::PAGE_SELECT_ACTION, mainHelper);
    backButton->setContentsMargins(0, 0, 0, 0);
}

void EditSettingsPage::resizeUiElements(MainHelper *mainHelper) {
    int mainWindowWidth = mainHelper->mainWindowWidth;
    int mainWindowHeight = mainHelper->mainWindowHeight;

    setGeometry(0, 0, mainWindowWidth, mainWindowHeight);

    backButton->setText(mainHelper->translate((char**)BACK_BUTTON_NAMES));

    if (mainWindowHeight >= mainWindowWidth * 3 / 4) {
        int margin = mainWindowWidth / NUMBER_OF_PARTS;
        int buttonWidth = mainWindowWidth - margin * 2;
        int buttonHeight = mainWindowHeight - margin * 2;

        backButton->setGeometry(margin, margin, buttonWidth, buttonHeight);
    }
    else {
        int margin = mainWindowHeight / NUMBER_OF_PARTS;
        int buttonWidth = mainWindowWidth - margin * 2;
        int buttonHeight = mainWindowHeight - margin * 2;

        backButton->setGeometry(margin, margin, buttonWidth, buttonHeight);
    }
}
