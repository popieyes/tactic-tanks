#pragma once
#include "Solid.h"

class Camera : public Solid
{
private:

public:
	Camera() : Solid(Vector3D(5.0, 2.0, 14.0), Color(), Vector3D(), Vector3D(), Vector3D()) {}
	Camera(Vector3D position, Color color, Vector3D orientation, Vector3D orientationSpeed, Vector3D speed) : Solid(position,color, orientation, orientationSpeed, speed) {}

	void Render();

};

