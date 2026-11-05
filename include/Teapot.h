#pragma once
#include "Solid.h"

class Teapot : public Solid
{
private:

	float size;

public:
	Teapot() : Solid(Vector3D(5.0, 0.6, -2.0), Color(0.2, 0.3, 0.4), Vector3D(30, 15, 35),Vector3D(0,0,0), Vector3D(0, 0, 0)),
		 size(0.3) {}
	
	inline float GetSize() const { return this->size; }
	
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }

	void Render();
};

