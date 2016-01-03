#include "mainHelper.h"
#include "page/selectLanguagePageButton.h"

SelectLanguagePageButton::SelectLanguagePageButton(const QString & text, QWidget * parent, int buttonNumber, MainHelper * mainHelper) : QPushButton(text, parent) {

    setContentsMargins(0, 0, 0, 0);

    this->buttonNumber = buttonNumber;
    this->mainHelper = mainHelper;

    connect(this, &QPushButton::clicked, this, &SelectLanguagePageButton::onClick);
}

SelectLanguagePageButton::~SelectLanguagePageButton() {

}

void SelectLanguagePageButton::onClick() {
    mainHelper->setCurrentLanguage(buttonNumber);
    mainHelper->setCurrentPage(MainHelper::PAGE_SELECT_ACTION);
}
