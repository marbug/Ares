#ifndef PAGE_HELPER_H
#define PAGE_HELPER_H

#include <QMainWindow>
#include "mainHelper.h"
#include "mainHelperSubscriber.h"
#include "page/editSettingsPage.h"
#include "page/selectActionPage.h"
#include "page/selectLanguagePage.h"

class PageHelper : public MainHelperSubscriber {
public:

    PageHelper(QMainWindow* window, MainHelper* mainHelper);
    ~PageHelper();

    void resizeUiElements();

    EditSettingsPage* editSettingsPage;
    void initEditSettingsPage();

    SelectActionPage* selectActionPage;
    void initSelectActionPage();

    SelectLanguagePage* selectLanguagePage;
    void initSelectLanguagePage();

    virtual void onSetCurrentPage() override;

private:

    QMainWindow* window;
    MainHelper* mainHelper;
};

#endif // PAGE_HELPER_H
