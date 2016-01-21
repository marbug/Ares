#include "mainHelper.h"

MainHelper::MainHelper() {
    this->currentLanguage = SUPPORTED_LANGUAGES_ENGLISH;
    this->currentPage = PAGE_SELECT_ACTION;
    this->osName = "";
    this->subscriber = 0;

    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    this->osName = "Linux";
#endif

    initSupportedLanguages();

}

MainHelper::~MainHelper() {
}

int MainHelper::getCurrentLanguage() {
    return currentLanguage;
}

void MainHelper::setCurrentLanguage(int newValue) {
    currentLanguage = newValue;
}

int MainHelper::getCurrentPage() {
    return currentPage;
}

void MainHelper::setCurrentPage(int newValue) {
    currentPage = newValue;

    if (subscriber != 0) {
        subscriber->onSetCurrentPage();
    }
}

void MainHelper::initSupportedLanguages() {
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_ENGLISH] ="English";
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_RUSSIAN] = "Русский";
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_UKRAINIAN] = "Українська";
}

void MainHelper::setSubscriber(MainHelperSubscriber* subscriber) {
    this->subscriber = subscriber;
}

char* MainHelper::translate(char** texts) {
    return texts[getCurrentLanguage()];
}
