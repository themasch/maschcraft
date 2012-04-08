#include "GLCamera.h"
#include <GL/glut.h>
#include <QDebug>
#include <math.h>

GLCamera::GLCamera()
{
    this->position.setZ(5);
}


void GLCamera::applyCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    QVector3D pointOfView = this->direction + this->position;
    gluLookAt(this->position.x(),    this->position.y(),    this->position.z(),
              pointOfView.x(),       pointOfView.y(),       pointOfView.z(),
              0, 1, 0);
}

void GLCamera::move(QVector3D move, int msec)
{
    qreal time = (msec/100.0);
    this->position = this->position + (-move.z()) * this->direction * time + move.x() * this->right * time;
}

void GLCamera::mouseMove(qreal x, qreal y)
{
    this->verticalAngle += y/10.0;
    this->horizontalAngle += x/10.0;
    this->direction.setX(cos(verticalAngle) * sin(horizontalAngle));
    this->direction.setY(sin(verticalAngle));
    this->direction.setZ(cos(verticalAngle) * cos(horizontalAngle));

    this->right.setX(sin(horizontalAngle - 3.14f/2.0f));
    this->right.setZ(cos(horizontalAngle - 3.14f/2.0f));
}
