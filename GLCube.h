#ifndef GLCUBE_H
#define GLCUBE_H

#include "Renderable.h"
#include <GL/glut.h>

class GLCube : public Renderable
{
public:
    GLCube();
    void draw();
    void record();

protected:
    static GLuint cubeid;
};

#endif // GLCUBE_H
