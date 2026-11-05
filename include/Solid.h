#pragma once
#include <GL/glew.h>
#include "Vector3D.h"
#include "Color.h"

class Solid
{
private:
	Vector3D coordinates;
	Color color;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D speed;

public:
	Solid() : coordinates(0.0, 0.0, 0.0),
		color(), orientation(0, 0, 0), orientationSpeed(0,0,0), speed(0,0,0) {}
	Solid(Vector3D initCoordinates, Color initColor, Vector3D initOrientation, Vector3D initOrientSpeed, Vector3D initSpeed) : coordinates(initCoordinates), color(initColor), orientation(initOrientation), orientationSpeed(initOrientSpeed), speed(initSpeed) {};
	inline Vector3D GetCoordinates() const { return coordinates; }
	inline Vector3D GetOrientation() const { return orientation; }
	inline Color GetColor() const { return color; }
	inline Vector3D GetOrientationSpeed() const { return orientationSpeed; }
	inline Vector3D GetSpeed() const { return speed; }

	inline void SetCoordinates(const Vector3D& coordinatesToSet) { this->coordinates = coordinatesToSet; }
	inline void SetOrientation(const Vector3D& orientationToSet) { this->orientation = orientationToSet; }
	inline void SetColor(const Color& colorToSet) { this->color = colorToSet; }
	inline void SetOrientationSpeed(const Vector3D& orientSpeedToSet) { this->orientationSpeed = orientSpeedToSet; }
	inline void SetSpeed(const Vector3D& speedToSet) { this->speed = speedToSet; }

	virtual void Render() = 0;
	virtual void Update(const float& time);
};

