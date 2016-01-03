#ifndef SELECT_LANGUAGE_PAGE_BUTTON_H
#define SELECT_LANGUAGE_PAGE_BUTTON_H

#include "mainHelper.h"
#include <QPushButton>
#include <QWidget>

class SelectLanguagePageButton {

    private:

        int buttonNumber;
        MainHelper * mainHelper;

    public:

        QPushButton * button;

        SelectLanguagePageButton(const QString & text, QWidget * parent, int buttonNumber, MainHelper * mainHelper);
        ~SelectLanguagePageButton();

        void onClick();
};

#endif // SELECT_LANGUAGE_PAGE_BUTTON_H
