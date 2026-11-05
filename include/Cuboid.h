#pragma once
#include "Solid.h"
class Cuboid : public Solid
{
private:
	float length;
	float height;
	float width;

public:
	Cuboid() : Solid(Vector3D(-3.0, -0.8, -4.2), Color(0.9, 0.9, 0.0), Vector3D(20, 15, -90), Vector3D(0,0,0),Vector3D(0, 0, 0)), length(1), height(1.5), width(1) {}

	inline float GetLength() const { return this->length; }
	inline float GetHeight() const { return this->height; }
	inline float GetWidth() const { return this->width; }

	inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

	void Render();

};

