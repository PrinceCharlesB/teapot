// 预处理器指令，防止头文件被重复包含
#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

// 确保只包含一次头文件
#pragma once

// 包含必要的OpenGL头文件
#include "qgl.h"
#include <GL/glu.h>
#include <glut-3.7.6/glut.h>

// 包含Qt的事件处理头文件
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QApplication>

// 声明MyOpenGLWidget类，继承自QGLWidget
class MyOpenGLWidget : public QGLWidget
{
public:
    // 构造函数，可以指定父窗口
    MyOpenGLWidget(QWidget *parent = nullptr) : QGLWidget(parent) {}
    // 重写QGLWidget的initializeGL函数，用于初始化OpenGL状态
    void initializeGL() override;
    // 重写QGLWidget的resizeGL函数，用于处理窗口尺寸变化
    void resizeGL(int w, int h) override;
    // 重写QGLWidget的paintGL函数，用于绘制OpenGL场景
    void paintGL() override;

    // 设置绕X轴旋转的角度
    void setRotationX(float angle);
    // 设置绕Y轴旋转的角度
    void setRotationY(float angle);
    // 设置缩放比例
    void setScaling(float scale);

protected:

    // 重写QWidget的mouseMoveEvent函数，处理鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;
    // 重写QWidget的wheelEvent函数，处理鼠标滚轮事件
    void wheelEvent(QWheelEvent *event) override;
    // 重写QWidget的showEvent函数，处理窗口显示事件
    void showEvent(QShowEvent *event) override;

private:
    // 存储绕X轴和Y轴的旋转角度
    GLfloat rotationX;
    GLfloat rotationY;
    // 存储缩放比例
    GLfloat scaling = 1;
    // 存储上次鼠标位置
    QPoint lastPos;
};

// 结束头文件的预处理器指令
#endif // MYOPENGLWIDGET_H
