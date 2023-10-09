#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
  //  w.resize(1024, 480); // 设置窗口大小为1024x480像素
    w.show();

    return a.exec();
}
