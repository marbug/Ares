#include "mainHelper.h"
#include "pageHelper.h"

PageHelper::PageHelper(QMainWindow* window, MainHelper* mainHelper) {
    this->window = window;
    this->mainHelper = mainHelper;
}

PageHelper::~PageHelper() {
}

void PageHelper::initSelectActionPage() {
    selectActionPage = new SelectActionPage();
    selectActionPage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectActionPage);

    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_ACTION);
}

void PageHelper::initSelectLanguagePage() {
    selectLanguagePage = new SelectLanguagePage();
    selectLanguagePage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectLanguagePage);

    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_LANGUAGE);
}

void PageHelper::resizeUiElements() {

    switch (mainHelper->getCurrentPage()) {

        case MainHelper::PAGE_SELECT_ACTION:
            selectActionPage->resizeUiElements(mainHelper);

        case MainHelper::PAGE_SELECT_LANGUAGE:
            selectLanguagePage->resizeUiElements(mainHelper);
    }
}
