#include "mainHelper.h"
#include "button/selectPageButton.h"

SelectPageButton::SelectPageButton(const QString & text, QWidget * parent, int newPageNumber, MainHelper * mainHelper) : QPushButton(text, parent) {

    setContentsMargins(0, 0, 0, 0);

    this->newPageNumber = newPageNumber;
    this->mainHelper = mainHelper;

    connect(this, &QPushButton::clicked, this, &SelectPageButton::onClick);
}

SelectPageButton::~SelectPageButton() {

}

void SelectPageButton::onClick() {
    mainHelper->setCurrentPage(newPageNumber);
}
