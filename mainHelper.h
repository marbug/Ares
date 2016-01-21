#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

#include <QString>
#include "mainHelperSubscriber.h"

class MainHelper {
public:

    enum {
        SUPPORTED_LANGUAGES_ENGLISH,
        SUPPORTED_LANGUAGES_RUSSIAN,
        SUPPORTED_LANGUAGES_UKRAINIAN,
        NUMBER_OF_SUPPORTED_LANGUAGES
    };

    enum {
        PAGE_EDIT_SETTINGS,
        PAGE_SELECT_ACTION,
        PAGE_SELECT_LANGUAGE
    };

    int displayHeight;
    int displayWidth;

    int mainWindowHeight;
    int mainWindowWidth;

    QString osName = "";

    const char* SUPPORTED_LANGUAGES[NUMBER_OF_SUPPORTED_LANGUAGES];

    MainHelper();
    ~MainHelper();

    int getCurrentLanguage();
    void setCurrentLanguage(int newValue);

    int getCurrentPage();
    void setCurrentPage(int newValue);

    void setSubscriber(MainHelperSubscriber* subscriber);

    char* translate(char** texts);

private:

    int currentLanguage = SUPPORTED_LANGUAGES_ENGLISH;
    int currentPage = PAGE_SELECT_ACTION;

    void initSupportedLanguages();

    MainHelperSubscriber* subscriber = 0;
};

#endif // MAIN_HELPER_H
