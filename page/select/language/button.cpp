#include "main/helper.h"
#include "page/select/language/button.h"

SelectLanguagePageButton::SelectLanguagePageButton(const QString & text, QWidget * parent, int buttonNumber, MainHelper * mainHelper) {
    button = new QPushButton(text, parent);

    button->setContentsMargins(0, 0, 0, 0);

    this->buttonNumber = buttonNumber;
    this->mainHelper = mainHelper;

    //connect(languageButtons[i], SIGNAL (pressed()),this, SLOT (onClick()));
}

SelectLanguagePageButton::~SelectLanguagePageButton() {

}

void SelectLanguagePageButton::onClick() {
}
