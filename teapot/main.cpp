// 包含自定义的OpenGL窗口部件头文件
#include "myopenglwidget.h"
// 包含QApplication类的头文件，它是所有Qt应用程序的主控件
#include <QApplication>

// main函数，程序的入口点
int main(int argc, char *argv[])
{
    // 创建一个QApplication对象，传入命令行参数和参数个数
    QApplication a(argc, argv);
     glutInit(&argc, argv);
    // 创建自定义的OpenGL窗口部件对象
    MyOpenGLWidget w;
    // 设置窗口部件的大小为500x500像素
    w.resize(500, 500);
    // 显示窗口部件
    w.show();
    // 进入Qt的事件循环，等待用户操作
    return a.exec();
}
