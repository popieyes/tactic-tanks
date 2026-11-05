#pragma once
#include "Camera.h"
#include "Model.h"
#include "Text.h"
#include "HUD.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI/180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0/ M_PI)


class ThirdPersonCamera : public Camera
{
private: 
	Model* target;
	HUD hud;
public:
	ThirdPersonCamera(Player* targetSet, Vector3D positionArgument = Vector3D()) : Camera(positionArgument, Color(0, 0, 0), Vector3D(20, 0, 0), Vector3D(0, 0, 0), Vector3D(0, 0, 0)), target(targetSet->getModel()), hud(targetSet) {}

	void Render(); 
	void Update(const float& time);

	inline Model* GetTarget() { return this->target; }
	inline void SetTarget(Model* targetToSet) { this->target = targetToSet; }
};

