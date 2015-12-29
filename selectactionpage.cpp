#include "mainhelper.h"
#include "selectactionpage.h"

SelectActionPage::SelectActionPage(MainHelper *mainHelper) {
    this->mainHelper = mainHelper;
}

SelectActionPage::~SelectActionPage() {

}

void SelectActionPage::prepareUiElements() {

    startButton = new QPushButton("Start", this);
    editButton = new QPushButton("Edit", this);
    statusBarLabel = new QPushButton("", this);
    statusBarLabel->setObjectName("statusBarLabel");
}

void SelectActionPage::resizeUiElements() {
    int mainWindowWidth = mainHelper->mainWindowWidth;
    int mainWindowHeight = mainHelper->mainWindowHeight;

    setContentsMargins(0, 0, 0, 0);
    setGeometry(0, 0, mainWindowWidth, mainWindowHeight);

    startButton->setContentsMargins(0, 0, 0, 0);
    editButton->setContentsMargins(0, 0, 0, 0);
    statusBarLabel->setContentsMargins(0, 0, 0, 0);

    int labelHeight = mainWindowWidth / MAIN_WINDOW_PARTS;
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


    statusBarLabel->setText(
        "Size: " + QString::number(mainWindowWidth) + "x" + QString::number(mainWindowHeight) +
        " (" + QString::number(mainHelper->displayWidth) + "x" + QString::number(mainHelper->displayHeight) +
        ")\nBuild " + __TIME__ + " " + mainHelper->osName
    );
    statusBarLabel->setGeometry(0, mainWindowHeight - labelHeight, mainWindowWidth, labelHeight);
}
