#include "GLCamera.h"
#include <GL/glut.h>
#include <QDebug>

GLCamera::GLCamera()
{
    this->position.setZ(5);
}


void GLCamera::applyCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(this->position.x(),    this->position.y(),    this->position.z(),
              this->pointOfView.x(), this->pointOfView.y(), this->pointOfView.z(),
              0, 1, 0);
}

void GLCamera::move(QVector3D move)
{
    this->pointOfView.setX(this->pointOfView.x() + move.x()/5);
    this->pointOfView.setY(this->pointOfView.y() + move.y()/5);
    this->pointOfView.setZ(this->pointOfView.z() + move.z()/5);
    this->position.setX(this->position.x() + move.x()/5);
    this->position.setY(this->position.y() + move.y()/5);
    this->position.setZ(this->position.z() + move.z()/5);
}

void GLCamera::mouseMove(qreal x, qreal y)
{
    this->pointOfView.setX(this->pointOfView.x() + x/10);
    this->pointOfView.setY(this->pointOfView.y() + y/10);
}
