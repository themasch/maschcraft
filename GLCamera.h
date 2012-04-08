#ifndef GLCAMERA_H
#define GLCAMERA_H

#include <QVector3D>

class GLCamera
{

public:
    GLCamera();
    void move(QVector3D relMove, int msec);
    void applyCamera();

public slots:
    void mouseMove(qreal x, qreal y);

protected:
    QVector3D position;
    QVector3D direction;
    QVector3D right;
    qreal verticalAngle;
    qreal horizontalAngle;
};

#endif // GLCAMERA_H
