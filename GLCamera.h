#ifndef GLCAMERA_H
#define GLCAMERA_H

#include <QVector3D>

class GLCamera
{

public:
    GLCamera();
    void move(QVector3D relMove);
    void applyCamera();

public slots:
    void mouseMove(qreal x, qreal y);

protected:
    QVector3D position;
    QVector3D pointOfView;
    QPointF oldMousePos;
};

#endif // GLCAMERA_H
