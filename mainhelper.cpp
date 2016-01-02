#include "mainhelper.h"

MainHelper::MainHelper() {

    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    osName = "Linux";
#endif

    initSupportedLanguages();

}

MainHelper::~MainHelper() {
}

void MainHelper::initSupportedLanguages() {
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_ENGLISH] ="English";
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_RUSSIAN] = "Русский";
    SUPPORTED_LANGUAGES[SUPPORTED_LANGUAGES_UKRAINIAN] = "Українська";
}
