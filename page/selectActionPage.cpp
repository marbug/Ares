#include "mainHelper.h"
#include "page/selectActionPage.h"

SelectActionPage::SelectActionPage() {
    initButtonNames();
}

SelectActionPage::~SelectActionPage() {

}

void SelectActionPage::initButtonNames() {
    EDIT_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_ENGLISH] ="Edit";
    EDIT_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_RUSSIAN] = "Изменить";
    EDIT_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_UKRAINIAN] = "Змінити";

    START_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_ENGLISH] ="Start";
    START_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_RUSSIAN] = "Начать";
    START_BUTTON_NAMES[MainHelper::SUPPORTED_LANGUAGES_UKRAINIAN] = "Почати";
}

void SelectActionPage::prepareUiElements(MainHelper *mainHelper) {

    setContentsMargins(0, 0, 0, 0);

    startButton = new QPushButton("Start", this);
    startButton->setContentsMargins(0, 0, 0, 0);

    editButton = new QPushButton("Edit", this);
    editButton->setContentsMargins(0, 0, 0, 0);

    statusBarLabel = new QPushButton("", this);
    statusBarLabel->setObjectName("statusBarLabel");
    statusBarLabel->setContentsMargins(0, 0, 0, 0);
}

void SelectActionPage::resizeUiElements(MainHelper *mainHelper) {
    int mainWindowWidth = mainHelper->mainWindowWidth;
    int mainWindowHeight = mainHelper->mainWindowHeight;

    setGeometry(0, 0, mainWindowWidth, mainWindowHeight);

    int labelHeight = mainWindowWidth / MAIN_WINDOW_PARTS;
    if (labelHeight < STATUS_BAR_MIN_HEIGHT) {
        labelHeight = STATUS_BAR_MIN_HEIGHT;
    }

    editButton->setText(mainHelper->translate((char**)EDIT_BUTTON_NAMES));
    startButton->setText(mainHelper->translate((char**)START_BUTTON_NAMES));

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


    statusBarLabel->setText(
        "Size: " + QString::number(mainWindowWidth) + "x" + QString::number(mainWindowHeight) +
        " (" + QString::number(mainHelper->displayWidth) + "x" + QString::number(mainHelper->displayHeight) +
        ")\nBuild " + __TIME__ + " " + mainHelper->osName
    );
    statusBarLabel->setGeometry(0, mainWindowHeight - labelHeight, mainWindowWidth, labelHeight);
}
