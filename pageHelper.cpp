#include "pageHelper.h"
#include "mainHelper.h"
#include "mainHelperSubscriber.h"

PageHelper::PageHelper(QMainWindow* window, MainHelper* mainHelper) : MainHelperSubscriber() {
    this->window = window;
    this->mainHelper = mainHelper;

    mainHelper->setSubscriber((MainHelperSubscriber*)this);
}

PageHelper::~PageHelper() {
}

void PageHelper::initSelectActionPage() {
    selectActionPage = new SelectActionPage();
    selectActionPage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectActionPage);

    //mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_ACTION);
}

void PageHelper::initSelectLanguagePage() {
    selectLanguagePage = new SelectLanguagePage();
    selectLanguagePage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectLanguagePage);

    //mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_LANGUAGE);
}

void PageHelper::resizeUiElements() {

    switch (mainHelper->getCurrentPage()) {

        case MainHelper::PAGE_SELECT_ACTION:
            if (selectActionPage == 0) {
                initSelectActionPage();
            }
            selectActionPage->resizeUiElements(mainHelper);
            break;

        case MainHelper::PAGE_SELECT_LANGUAGE:
            if (selectLanguagePage == 0) {
                initSelectLanguagePage();
            }
            selectLanguagePage->resizeUiElements(mainHelper);
            break;
    }
}

void PageHelper::onSetCurrentPage() {
    resizeUiElements();
}
