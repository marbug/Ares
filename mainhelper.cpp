#include "mainhelper.h"

MainHelper::MainHelper() {

    // Qt 4/5 on Ubuntu does place the native menubar correctly so on Linux we revert back to in-window menu bar.
#ifdef Q_OS_LINUX
    osName = "Linux";
#endif

}

MainHelper::~MainHelper() {
}
