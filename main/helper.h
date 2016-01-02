#ifndef MAINHELPER_H
#define MAINHELPER_H

#include <QString>

class MainHelper {

    public:

        enum {
            SUPPORTED_LANGUAGES_ENGLISH,
            SUPPORTED_LANGUAGES_RUSSIAN,
            SUPPORTED_LANGUAGES_UKRAINIAN,
            NUMBER_OF_SUPPORTED_LANGUAGES
        };
        int currentLanguage = SUPPORTED_LANGUAGES_ENGLISH;

        enum {
            PAGE_SELECT_ACTION,
            PAGE_SELECT_LANGUAGE
        };
        int currentPage = PAGE_SELECT_ACTION;

        int displayHeight;
        int displayWidth;

        int mainWindowHeight;
        int mainWindowWidth;

        QString osName = "";

        const char* SUPPORTED_LANGUAGES[NUMBER_OF_SUPPORTED_LANGUAGES];

        MainHelper();
        ~MainHelper();

    private:

        void initSupportedLanguages();
};

#endif // MAINHELPER_H
