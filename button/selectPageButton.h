#ifndef SELECT_ACTION_PAGE_BUTTON_H
#define SELECT_ACTION_PAGE_BUTTON_H

#include "mainHelper.h"
#include <QPushButton>
#include <QWidget>

class SelectPageButton : public QPushButton {
private:

    int newPageNumber;
    MainHelper * mainHelper;

public:

    SelectPageButton(const QString & text, QWidget * parent, int newPageNumber, MainHelper * mainHelper);
    ~SelectPageButton();

    void onClick();
};

#endif // SELECT_ACTION_PAGE_BUTTON_H
