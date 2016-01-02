#ifndef SELECTLANGUAGEPAGE_H
#define SELECTLANGUAGEPAGE_H

#include "main/helper.h"
#include <QPushButton>

class SelectLanguagePage : public QWidget {

    private:

        const int MARGIN_PART = 10;

        QPushButton *languageButtons[MainHelper::NUMBER_OF_SUPPORTED_LANGUAGES];

    public:

        SelectLanguagePage();
        ~SelectLanguagePage();

        void prepareUiElements(MainHelper *mainHelper);
        void resizeUiElements(MainHelper *mainHelper);
};

#endif // SELECTLANGUAGEPAGE_H
