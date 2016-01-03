#include "mainHelper.h"
#include "page/selectActionPageButton.h"

SelectActionPageButton::SelectActionPageButton(const QString & text, QWidget * parent, int newPageNumber, MainHelper * mainHelper) : QPushButton(text, parent) {

    setContentsMargins(0, 0, 0, 0);

    this->newPageNumber = newPageNumber;
    this->mainHelper = mainHelper;

    connect(this, &QPushButton::clicked, this, &SelectActionPageButton::onClick);
}

SelectActionPageButton::~SelectActionPageButton() {

}

void SelectActionPageButton::onClick() {
    mainHelper->setCurrentPage(newPageNumber);
}
