#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <QVector3D>
#include <QDebug>

class Renderable
{
public:
    Renderable();
    virtual void prepareMatrix();
    virtual void resetMatrix();
    virtual void draw() = 0;
    virtual void render();

    void setPosition(QVector3D pos);
    void setSize(QVector3D size);
    void rotate(qreal x, qreal y, qreal z);


protected:
    QVector3D scale;
    QVector3D position;
    QVector3D rotation;

};

#endif // RENDERABLE_H
