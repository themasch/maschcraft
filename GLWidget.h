#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include "GLSceneNode.h"
#include "GLCamera.h"
#include <QTime>
#include <QVector2D>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

protected:
    void mouseMoveEvent(QMouseEvent *evt);
    void keyPressEvent(QKeyEvent *evt);
    void keyReleaseEvent(QKeyEvent *evt);

private:
    int    frames;
    int    renderBoxes;
    QTime  time;
    QTimer timer;
    GLSceneNode root;
    QVector3D pov;
    QVector3D playerPosition;
    QVector2D relMouseOffset;
    QVector3D relMove;
    GLCamera cam;

signals:
    void updateFps(int fps);
    
public slots:
    
};

#endif // GLWIDGET_H
