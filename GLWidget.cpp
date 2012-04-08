#include "GLWidget.h"
#include <QDebug>
#include <GL/glut.h>
#include <QVector3D>
#include <QVector2D>
#include <QTime>
#include <QMouseEvent>
#include <QKeyEvent>
#include "GLCube.h"

bool firstMove = true;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(8);
    time.start();
    frames = 0;
    renderBoxes = 420;
    GLCube *cube;
    for(int j=0;j<30;j++)
    for(int i=0;i<30;i++) {
        cube = new GLCube();
        cube->setPosition(QVector3D(i-15, rand() % 3 - 5, j-15));
        this->root.addObject(cube);
    }

    this->setMouseTracking(true);
    this->setCursor( QCursor( Qt::BlankCursor ) );
    this->setFocus();
    this->setFocusPolicy(Qt::StrongFocus);

}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    glEnable (GL_BLEND);
    glEnable(GL_POLYGON_SMOOTH);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel (GL_FLAT);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    GLfloat l0Ambient[] = {0.3, 0.3, 0.3, 0.4};

    glLightfv(GL_LIGHT0, GL_AMBIENT, l0Ambient);

    glClearColor(.3,.3,.3, 1);
}

void GLWidget::paintGL()
{
    // move camera pov
    this->cam.move(this->relMove);
    this->cam.applyCamera();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.5, 1, 0.5);
    this->root.render();

    this->frames++;
    if(time.elapsed() >= 1000) {
        int fps = this->frames / (time.elapsed() / 1000);
        this->frames = 0;
        time.restart();
        this->updateFps(fps);
    }
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    this->cam.applyCamera();
}

void GLWidget::mouseMoveEvent(QMouseEvent *evt)
{
    QPoint center = this->mapToGlobal(QPoint(this->width()/2, this->height()/2));
    QCursor::setPos(center);

    if(!firstMove) {
        qreal offX = (qreal)evt->x() - (this->width()/2);
        qreal offY = (qreal)evt->y() - (this->height()/2);
        this->cam.mouseMove(offX/10.0, offY/-10.0);
    } else {
        firstMove = false;
    }
}

void GLWidget::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_A:
        this->relMove.setX(-1);
        break;
    case Qt::Key_D:
        this->relMove.setX(1);
        break;
    case Qt::Key_W:
        this->relMove.setZ(-1);
        break;
    case Qt::Key_S:
        this->relMove.setZ(1);
        break;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_A:
    case Qt::Key_D:
        this->relMove.setX(0);
        break;
    case Qt::Key_W:
    case Qt::Key_S:
        this->relMove.setZ(0);
        break;
    }
}
