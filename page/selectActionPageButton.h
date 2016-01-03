#ifndef SELECT_ACTION_PAGE_BUTTON_H
#define SELECT_ACTION_PAGE_BUTTON_H

#include "mainHelper.h"
#include <QPushButton>
#include <QWidget>

class SelectActionPageButton : public QPushButton {
private:

    int newPageNumber;
    MainHelper * mainHelper;

public:

    SelectActionPageButton(const QString & text, QWidget * parent, int newPageNumber, MainHelper * mainHelper);
    ~SelectActionPageButton();

    void onClick();
};

#endif // SELECT_ACTION_PAGE_BUTTON_H
