#ifndef PAGE_HELPER_H
#define PAGE_HELPER_H

#include <QMainWindow>
#include "mainHelper.h"
#include "page/selectActionPage.h"
#include "page/selectLanguagePage.h"

class PageHelper : public MainHelperSubscriber {

    public:

        PageHelper(QMainWindow* window, MainHelper* mainHelper);
        ~PageHelper();

        void resizeUiElements();

        SelectActionPage* selectActionPage = 0;
        void initSelectActionPage();

        SelectLanguagePage* selectLanguagePage = 0;
        void initSelectLanguagePage();

    private:

        QMainWindow* window;
        MainHelper* mainHelper;

        void onSetCurrentPage();
};

#endif // PAGE_HELPER_H
