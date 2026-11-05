#pragma once
#include "Solid.h"
class Cube : public Solid
{
private:

	float size;

public:
	Cube() : Solid(Vector3D(1, 0.5, -2.0), Color(0.85, 0.4, 0.0), Vector3D(30, 40, 55), Vector3D(0,0,0), Vector3D(0,0,0)), size(0.4) {}
	
	inline float GetSize() const { return this->size; }
	
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();

};

