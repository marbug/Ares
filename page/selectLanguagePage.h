#ifndef SELECT_LANGUAGE_PAGE_H
#define SELECT_LANGUAGE_PAGE_H

#include "mainHelper.h"
#include "page/selectLanguagePageButton.h"

class SelectLanguagePage : public QWidget {
private:

    const int NUMBER_OF_PARTS = 10;

    SelectLanguagePageButton *languageButtons[MainHelper::NUMBER_OF_SUPPORTED_LANGUAGES];

public:

    SelectLanguagePage();
    ~SelectLanguagePage();

    void prepareUiElements(MainHelper *mainHelper);
    void resizeUiElements(MainHelper *mainHelper);
};

#endif // SELECT_LANGUAGE_PAGE_H
