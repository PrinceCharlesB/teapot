#include "myopenglwidget.h"

// 初始化OpenGL状态和设置
void MyOpenGLWidget::initializeGL()
{
    // 设置平滑着色模式
    glShadeModel(GL_SMOOTH);
    // 设置清除屏幕时使用的颜色为黑色，透明度为0
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // 设置深度缓冲区的清除值
    glClearDepth(1.0);
    // 启用深度测试
    glEnable(GL_DEPTH_TEST);
    // 设置深度测试函数，使用小于等于测试
    glDepthFunc(GL_LEQUAL);
    // 设置透视校正的提示为最细致
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// 处理窗口尺寸变化时的OpenGL视图调整
void MyOpenGLWidget::resizeGL(int w, int h)
{
    // 设置视口大小
    glViewport(0, 0, w, h);
    // 设置矩阵模式为投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 重置投影矩阵
    glLoadIdentity();
    // 定义透视投影，设置视场角度、纵横比、近裁剪面和远裁剪面
    gluPerspective(45.0, w/h, 0.1, 100.0);
    // 设置矩阵模式为模型视图矩阵
    glMatrixMode(GL_MODELVIEW);
    // 重置模型视图矩阵
    glLoadIdentity();
}

// 绘制OpenGL场景
void MyOpenGLWidget::paintGL()
{
    // 清除颜色和深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // 重置当前矩阵到单位矩阵
    glLoadIdentity();
    // 设置当前绘制颜色为红色
    glColor3f(1.0f, 0.0f, 0.0f);
    // 平移视图到Z轴负方向
    glTranslatef(0.0f, 0.0f, -10.0f);
    // 绕X轴旋转
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f);
    // 绕Y轴旋转
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    // 均匀缩放
    glScalef(scaling, scaling, scaling);
    // 绘制一个线框茶壶
    glutWireTeapot(2);
}


// 设置绕Y轴的旋转角度，并触发重绘操作
void MyOpenGLWidget::setRotationY(float angle)
{
    // 更新绕Y轴的旋转角度
    rotationY = angle;
    // 调用update()函数，这将导致窗口部件在下一次事件循环中重绘
    update();
}

// 设置缩放比例，并触发重绘操作
void MyOpenGLWidget::setScaling(float scale)
{
    // 更新缩放比例
    scaling = scale;
    // 调用update()函数，这将导致窗口部件在下一次事件循环中重绘
    update();
}

// 处理鼠标移动事件，实现旋转操作
void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 计算自上次鼠标事件以来鼠标水平和垂直方向的移动距离
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    // 检查是否按下了鼠标左键
    if (event->buttons() & Qt::LeftButton)
    {
        // 如果按下左键，根据鼠标移动调整绕X轴和Y轴的旋转角度
        // dy和dx的值乘以0.5是为了控制旋转速度
        rotationX += dy * 0.5f;
        rotationY += dx * 0.5f;
        // 调用update()函数，请求重绘窗口以反映旋转变化
        update();
    }

    // 更新lastPos为当前鼠标位置，为下一次事件处理做准备
    lastPos = event->pos();
}

// 处理鼠标滚轮事件，实现缩放操作
void MyOpenGLWidget::wheelEvent(QWheelEvent *event)
{
    // 获取滚轮的滚动量
    int delta = event->delta();
    // 根据滚动量调整缩放比例，向上滚动增加缩放，向下滚动减少缩放
    scaling += (delta > 0) ? 0.1f : -0.1f;
    // 限制缩放比例的最小值为0.1，防止缩放过小导致渲染问题
    if (scaling < 0.1f) scaling = 0.1f;
    // 调用update()函数，请求重绘窗口以反映缩放变化
    update();
}

// 处理窗口显示事件，实现窗口的居中显示
void MyOpenGLWidget::showEvent(QShowEvent *event)
{
    // 获取当前桌面的大小
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    // 计算窗口的新位置，使其在屏幕中心显示
    int x = (screenWidth - width()) / 2;
    int y = (screenHeight - height()) / 2;
    // 移动窗口到新计算的位置
    move(x, y);

    // 调用基类QGLWidget的showEvent函数，以确保正常处理其他与显示相关的事件
    QGLWidget::showEvent(event);
}
