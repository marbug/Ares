#ifndef MAINHELPER_H
#define MAINHELPER_H

#include <QString>

class MainHelper {

    public:

        int displayHeight;
        int displayWidth;

        int mainWindowHeight;
        int mainWindowWidth;

        QString osName = "";

        MainHelper();
        ~MainHelper();
};

#endif // MAINHELPER_H
