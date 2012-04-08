#include "Renderable.h"
#include <GL/glut.h>

Renderable::Renderable()
{
    this->scale.setX(1);
    this->scale.setY(1);
    this->scale.setZ(1);
}

void Renderable::prepareMatrix()
{
    glPushMatrix();
    glTranslated(this->position.x(),
                 this->position.y(),
                 this->position.z());
    glScaled(this->scale.x(),
             this->scale.y(),
             this->scale.z());
    glRotated(this->rotation.x(), 1, 0, 0);
    glRotated(this->rotation.y(), 0, 1, 0);
    glRotated(this->rotation.z(), 0, 0, 1);
}

void Renderable::resetMatrix()
{
    glPopMatrix();
    /*
    glRotated(this->rotation.z(), 0, 0, -1);
    glRotated(this->rotation.y(), 0, -1, 0);
    glRotated(this->rotation.x(), -1, 0, 0);
    glScaled(1/(this->scale.x()),
             1/(this->scale.y()),
             1/(this->scale.z()));
    glTranslated((-1) * this->position.x(),
                 (-1) * this->position.y(),
                 (-1) * this->position.z());*/
}

void Renderable::render()
{
    this->prepareMatrix();
    this->draw();
    this->resetMatrix();
}

void Renderable::setPosition(QVector3D pos)
{
    this->position = pos;
}

void Renderable::setSize(QVector3D size)
{
    this->scale = size;
}

void Renderable::rotate(qreal x, qreal y, qreal z)
{
    this->rotation += QVector3D(x, y, z);
}
