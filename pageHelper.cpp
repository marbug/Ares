#include "pageHelper.h"
#include "mainHelper.h"
#include "mainHelperSubscriber.h"

PageHelper::PageHelper(QMainWindow* window, MainHelper* mainHelper) : MainHelperSubscriber() {
    this->editSettingsPage = 0;
    this->selectActionPage = 0;
    this->selectLanguagePage = 0;

    this->window = window;
    this->mainHelper = mainHelper;

    mainHelper->setSubscriber((MainHelperSubscriber*)this);
}

PageHelper::~PageHelper() {
}

void PageHelper::initEditSettingsPage() {
    editSettingsPage = new EditSettingsPage();
    editSettingsPage->prepareUiElements(mainHelper);
    window->setCentralWidget(editSettingsPage);
}

void PageHelper::initSelectActionPage() {
    selectActionPage = new SelectActionPage();
    selectActionPage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectActionPage);
}

void PageHelper::initSelectLanguagePage() {
    selectLanguagePage = new SelectLanguagePage();
    selectLanguagePage->prepareUiElements(mainHelper);
    window->setCentralWidget(selectLanguagePage);
}

void PageHelper::resizeUiElements() {

    switch (mainHelper->getCurrentPage()) {

        case MainHelper::PAGE_EDIT_SETTINGS:
            if (editSettingsPage != 0) {
                editSettingsPage->resizeUiElements(mainHelper);
            }
            break;

        case MainHelper::PAGE_SELECT_ACTION:
            if (selectActionPage != 0) {
                selectActionPage->resizeUiElements(mainHelper);
            }
            break;

        case MainHelper::PAGE_SELECT_LANGUAGE:
            if (selectLanguagePage != 0) {
                selectLanguagePage->resizeUiElements(mainHelper);
            }
            break;
    }
}

void PageHelper::onSetCurrentPage() {
    switch (mainHelper->getCurrentPage()) {

        case MainHelper::PAGE_EDIT_SETTINGS:
            initEditSettingsPage();
            break;

        case MainHelper::PAGE_SELECT_ACTION:
            initSelectActionPage();
            break;

        case MainHelper::PAGE_SELECT_LANGUAGE:
            initSelectLanguagePage();
            break;
    }

    resizeUiElements();
}
