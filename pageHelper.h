#ifndef PAGE_HELPER_H
#define PAGE_HELPER_H

#include <QMainWindow>
#include "mainHelper.h"
#include "page/selectActionPage.h"
#include "page/selectLanguagePage.h"

class PageHelper {

    public:

        PageHelper(QMainWindow* window, MainHelper* mainHelper);
        ~PageHelper();

        void resizeUiElements();

        SelectActionPage *selectActionPage;
        void initSelectActionPage();

        SelectLanguagePage *selectLanguagePage;
        void initSelectLanguagePage();

    private:

        QMainWindow* window;
        MainHelper* mainHelper;
};

#endif // PAGE_HELPER_H
