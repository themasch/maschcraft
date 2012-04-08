#include "GLSceneNode.h"

GLSceneNode::GLSceneNode()
{
}

void GLSceneNode::draw()
{
    QListIterator<Renderable*> it(this->objects);
    while(it.hasNext()) {
        Renderable *r = it.next();
        r->render();
    }
}

void GLSceneNode::addObject(Renderable *obj)
{
    this->objects.append(obj);
}
