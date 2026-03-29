#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

// Placeholder controller for camera/3D functionality (Phase 3).
class CameraController : public QObject {
    Q_OBJECT
    QML_ELEMENT

public:
    explicit CameraController(QObject *parent = nullptr) : QObject(parent) {}
    ~CameraController() override = default;
};

#endif // CAMERACONTROLLER_H
