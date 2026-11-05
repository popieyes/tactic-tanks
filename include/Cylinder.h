#pragma once
#include "Solid.h"

class Cylinder : public Solid
{
private:

	float baseRadius;
	float topRadius;
	float height;
	int slices;
	int stacks;

public:
	Cylinder() : Solid(Vector3D(0.2, -0.2, -4.2), Color(0.3, 0.9, 0.0), Vector3D(130, 0.0, 80.0),Vector3D(0,0,0), Vector3D(0, 0, 0)), baseRadius(0.5), topRadius(0.5), height(2.1), slices(30), stacks(30) {}

	inline float GetBaseRadius() const { return this->baseRadius; }
	inline float GetTopRadius() const { return this->topRadius; }
	inline int GetHeight() const { return this->height; }
	inline int GetSlices() const { return this->slices; }
	inline int GetStacks() const { return this->stacks; }

	inline void SetBaseRadius(const float& baseRadiusToSet) { this->baseRadius = baseRadiusToSet; }
	inline void SetTopRadius(const float& topRadiusToSet) { this->topRadius = topRadiusToSet; }
	inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
	inline void SetSlices(const float& slicesToSet) { this->slices = slicesToSet; }
	inline void SetStacks(const float& stacksToSet) { this->stacks = stacksToSet; }

	void Render();

};

