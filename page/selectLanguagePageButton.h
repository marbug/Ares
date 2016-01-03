#ifndef SELECT_LANGUAGE_PAGE_BUTTON_H
#define SELECT_LANGUAGE_PAGE_BUTTON_H

#include "mainHelper.h"
#include <QPushButton>
#include <QWidget>

class SelectLanguagePageButton : public QPushButton {

    private:

        int buttonNumber;
        MainHelper * mainHelper;

    public:

        SelectLanguagePageButton(const QString & text, QWidget * parent, int buttonNumber, MainHelper * mainHelper);
        ~SelectLanguagePageButton();

        void onClick();
};

#endif // SELECT_LANGUAGE_PAGE_BUTTON_H
