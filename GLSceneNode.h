#ifndef GLSCENENODE_H
#define GLSCENENODE_H

#include <QList>
#include "Renderable.h"

class GLSceneNode : public Renderable
{
public:
    GLSceneNode();
    void draw();
    void addObject(Renderable *obj);

protected:
    QList<Renderable*> objects;
};

#endif // GLSCENENODE_H
