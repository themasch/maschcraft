#include "GLCube.h"
#include <GL/glut.h>

GLuint GLCube::cubeid = -1;


GLfloat vertices[] = { 0.5, 0.5, 0.5,  -0.5, 0.5, 0.5,  -0.5,-0.5, 0.5,   0.5,-0.5, 0.5,   // v0,v0.5,v2,v3 (front)
                       0.5, 0.5, 0.5,   0.5,-0.5, 0.5,   0.5,-0.5,-0.5,   0.5, 0.5,-0.5,   // v0,v3,v4,v5 (right)
                       0.5, 0.5, 0.5,   0.5, 0.5,-0.5,  -0.5, 0.5,-0.5,  -0.5, 0.5, 0.5,   // v0,v5,v6,v0.5 (top)
                      -0.5, 0.5, 0.5,  -0.5, 0.5,-0.5,  -0.5,-0.5,-0.5,  -0.5,-0.5, 0.5,   // v0.5,v6,v7,v2 (left)
                      -0.5,-0.5,-0.5,   0.5,-0.5,-0.5,   0.5,-0.5, 0.5,  -0.5,-0.5, 0.5,   // v7,v4,v3,v2 (bottom)
                       0.5,-0.5,-0.5,  -0.5,-0.5,-0.5,  -0.5, 0.5,-0.5,   0.5, 0.5,-0.5 }; // v4,v7,v6,v5 (back)
GLfloat normals[]  = { 0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,   // v0,v1,v2,v3 (front)
                       1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,   // v0,v3,v4,v5 (right)
                       0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,   // v0,v5,v6,v1 (top)
                      -1, 0, 0,  -1, 0, 0,  -1, 0, 0,  -1, 0, 0,   // v1,v6,v7,v2 (left)
                       0,-1, 0,   0,-1, 0,   0,-1, 0,   0,-1, 0,   // v7,v4,v3,v2 (bottom)
                       0, 0,-1,   0, 0,-1,   0, 0,-1,   0, 0,-1 }; // v4,v7,v6,v5 (back)

// index array of vertex array for glDrawElements() & glDrawRangeElement()
// Notice the indices are listed straight from beginning to end as exactly
// same order of vertex array without hopping, because of different normals at
// a shared vertex. For this case, glDrawArrays() and glDrawElements() have no
// difference.
GLubyte indices[]  = { 0, 1, 2,   2, 3, 0,      // front
                       4, 5, 6,   6, 7, 4,      // right
                       8, 9,10,  10,11, 8,      // top
                      12,13,14,  14,15,12,      // left
                      16,17,18,  18,19,16,      // bottom
                      20,21,22,  22,23,20 };    // back



GLCube::GLCube()
{
    this->scale.setX(1);
    this->scale.setZ(1);
    this->scale.setY(1);
}

void GLCube::record()
{
    glNewList(GLCube::cubeid, GL_COMPILE);
//        glBegin(GL_QUADS);
//            glVertex3f(-0.5,  0.5, 0.5);
//            glVertex3f(-0.5, -0.5, 0.5);
//            glVertex3f( 0.5, -0.5, 0.5);
//            glVertex3f( 0.5,  0.5, 0.5);

//            glVertex3f( 0.5,  0.5, -0.5);
//            glVertex3f( 0.5, -0.5, -0.5);
//            glVertex3f(-0.5, -0.5, -0.5);
//            glVertex3f(-0.5,  0.5, -0.5);

//            glVertex3f(-0.5,  0.5, -0.5);
//            glVertex3f(-0.5,  0.5,  0.5);
//            glVertex3f( 0.5,  0.5,  0.5);
//            glVertex3f( 0.5,  0.5, -0.5);

//            glVertex3f( 0.5, -0.5, -0.5);
//            glVertex3f( 0.5, -0.5,  0.5);
//            glVertex3f( 0.5,  0.5,  0.5);
//            glVertex3f( 0.5,  0.5, -0.5);

//            glVertex3f(-0.5, -0.5, -0.5);
//            glVertex3f(-0.5, -0.5,  0.5);
//            glVertex3f( 0.5, -0.5,  0.5);
//            glVertex3f( 0.5, -0.5, -0.5);

//            glVertex3f(-0.5, -0.5, -0.5);
//            glVertex3f(-0.5, -0.5,  0.5);
//            glVertex3f(-0.5,  0.5,  0.5);
//            glVertex3f(-0.5,  0.5, -0.5);
//        glEnd();

        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glNormalPointer(GL_FLOAT, 0, normals);
        glVertexPointer(3, GL_FLOAT, 0, vertices);

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
    glEndList();
}

void GLCube::draw()
{
  /*  if(GLCube::cubeid == -1) {
        GLCube::cubeid = glGenLists(1);
        this->record();
        qDebug() << GLCube::cubeid << "\n";
    }
    glCallList(GLCube::cubeid);*/
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normals);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}
