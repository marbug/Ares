#include "mainHelper.h"
#include "page/selectLanguagePage.h"

SelectLanguagePage::SelectLanguagePage() {
}

SelectLanguagePage::~SelectLanguagePage() {

}

void SelectLanguagePage::prepareUiElements(MainHelper *mainHelper) {

    setContentsMargins(0, 0, 0, 0);

    for (int i; i < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES; i++) {
        languageButtons[i] = new SelectLanguagePageButton(mainHelper->SUPPORTED_LANGUAGES[i], this, i, mainHelper);
    }
}

void SelectLanguagePage::resizeUiElements(MainHelper *mainHelper) {
    int mainWindowWidth = mainHelper->mainWindowWidth;
    int mainWindowHeight = mainHelper->mainWindowHeight;

    setGeometry(0, 0, mainWindowWidth, mainWindowHeight);

    int buttonsPerLine = 1;
    int buttonsPerColumn = 1;
    if (mainWindowWidth >= mainWindowHeight) {
        buttonsPerLine = mainWindowWidth / mainWindowHeight;
        if (buttonsPerLine > mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
            buttonsPerLine = mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES;
        }
        if ((buttonsPerLine * buttonsPerColumn) < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
            buttonsPerLine = buttonsPerLine + 1;
            if ((buttonsPerLine * buttonsPerColumn) < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
                buttonsPerColumn = buttonsPerColumn + 1;
            }
        }
    }
    else {
        buttonsPerColumn = mainWindowHeight / mainWindowWidth;
        if (buttonsPerColumn > mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
            buttonsPerColumn = mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES;
        }
        if ((buttonsPerLine * buttonsPerColumn) < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
            buttonsPerColumn = buttonsPerColumn + 1;
            if ((buttonsPerLine * buttonsPerColumn) < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
                buttonsPerLine = buttonsPerLine + 1;
            }
        }
    }

    int margin = (mainWindowWidth >= mainWindowHeight) ? (mainWindowWidth / buttonsPerLine / MARGIN_PART / 2) : (mainWindowHeight / buttonsPerColumn / MARGIN_PART / 2);

    int buttonWidth = (mainWindowWidth - margin * 2) / buttonsPerLine;
    int buttonHeight = (mainWindowHeight - margin * 2) / buttonsPerColumn;

    int buttonNumber = 0;
    for (int j = 0; j < buttonsPerColumn; j++) {
        for (int i = 0; i < buttonsPerLine; i++) {
            if (buttonNumber < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
                int buttonX = i * buttonWidth + margin * 2;
                int buttonY = j * buttonHeight + margin * 2;
                int buttonW = buttonWidth - margin * 2;
                int buttonH = buttonHeight - margin * 2;

                languageButtons[j * buttonsPerLine + i]->setGeometry(buttonX, buttonY, buttonW, buttonH);
            }
            buttonNumber++;
        }
    }
}

