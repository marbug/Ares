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

    int buttonWidth = mainWindowWidth / buttonsPerLine;
    int buttonHeight = mainWindowHeight / buttonsPerColumn;

    int marginX = buttonWidth / MARGIN_PART / 2;
    int marginY = buttonHeight / MARGIN_PART / 2;

    int buttonNumber = 0;
    for (int y = 0; y < buttonsPerColumn; y++) {
        for (int x = 0; x < buttonsPerLine; x++) {
            if (buttonNumber < mainHelper->NUMBER_OF_SUPPORTED_LANGUAGES) {
                languageButtons[y * buttonsPerLine + x]->button->setGeometry(
                    x * buttonWidth + marginX, y * buttonHeight + marginY,
                    buttonWidth - marginX * 2, buttonHeight - marginY * 2
                );
            }
            buttonNumber++;
        }
    }
}

