#pragma once
#include "Solid.h"

class Torus : public Solid
{
private:
	float extRadius;
	float intRadius;
	int faces;
	int rings;

public:
	Torus() : Solid(Vector3D(1.3, -0.5, -2.0), Color(1.0, 0.2, 0.7), Vector3D(140.0, 40.0, 0.0),Vector3D(0,0,0), Vector3D(0, 0, 0)), extRadius(0.2), intRadius(0.08), faces(30), rings(30) {}

	inline float GetExtRadius() const { return this->extRadius; }
	inline float GetIntRadius() const { return this->intRadius; }
	inline int GetFaces() const { return this->faces; }
	inline int GetRings() const { return this->rings; }

	inline void SetExtRadius(const float& extRadiusToSet) { this->extRadius = extRadiusToSet; }
	inline void SetIntRadius(const float& intRadiusToSet) { this->intRadius = intRadiusToSet; }
	inline void SetFaces(const float& facesToSet) { this->faces = facesToSet; }
	inline void SeRings(const float& ringsToSet) { this->rings = ringsToSet; }

	void Render();

};

