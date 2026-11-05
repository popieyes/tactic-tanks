#pragma once
#include "Solid.h"

class Sphere : public Solid
{
private:
	int slices;
	int slacks;
	float radius;

public:
	Sphere() : Solid(Vector3D(-1.0, 0.5, -2.0), Color(1.0, 0.0, 0.0), Vector3D(20, 15, 35),Vector3D(0,0,0), Vector3D(0, 0, 0)), radius(0.2), slices(50), slacks(50) {}

	inline float GetRadius() const { return this->radius; }

	inline int GetSlices() const { return this->slices; }

	inline int GetSlacks() const { return this->slacks; }

	inline void SetRadius(const float& sizeToSet) { this->radius = sizeToSet; }

	inline void SetSlices(const int& sliceToSet) { this->slices = sliceToSet; }

	inline void SetSlacks(const int& slackToSet) { this->slacks = slackToSet; }

	void Render();

};

