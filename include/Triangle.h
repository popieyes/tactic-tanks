#pragma once
#include "Solid.h"

class Triangle : public Solid
{
private:
	Vector3D vx0;
	Vector3D vx1;
	Vector3D vx2;
	Vector3D normal0;
	Vector3D normal1;
	Vector3D normal2;
	Color color0;
	Color color1;
	Color color2;

public:
	Triangle() : Solid() {} 
	Triangle(Vector3D vertex0, Vector3D vertex1, Vector3D vertex2, Vector3D normalx, Vector3D normaly, Vector3D normalz) : vx0(vertex0),vx1(vertex1),vx2(vertex2),normal0(normalx),normal1(normaly),normal2(normalz) {}

	Vector3D inline GetVertex0() const { return this->vx0;}
	Vector3D inline GetVertex1() const { return this->vx1;}
	Vector3D inline GetVertex2() const { return this->vx2;}

	Vector3D inline GetNormal0() const { return this->normal0; }
	Vector3D inline GetNormal1() const { return this->normal1; }
	Vector3D inline GetNormal2() const { return this->normal2; }

	Color inline GetColor0() const { return this->color0; }
	Color inline GetColor1() const { return this->color1; }
	Color inline GetColor2() const { return this->color2; }

	void inline SetVertex0(const Vector3D& vertex0ToSet)  { this->vx0 =vertex0ToSet; }
	void inline SetVertex1(const Vector3D& vertex1ToSet)  { this->vx1=vertex1ToSet; }
	void inline SetVertex2(const Vector3D& vertex2ToSet)  { this->vx2=vertex2ToSet; }

	void inline SetNormal0(const Vector3D& normal0ToSet) { this->normal0 = normal0ToSet; }
	void inline SetNormal1(const Vector3D& normal1ToSet) { this->normal1 = normal1ToSet; }
	void inline SetNormal2(const Vector3D& normal2ToSet) { this->normal2 = normal2ToSet; }

	void inline SetColor0(const Color& color0ToSet) { this->color0 = color0ToSet; }
	void inline SetColor1(const Color& color1ToSet) { this->color1 = color1ToSet; }
	void inline SetColor2(const Color& color2ToSet) { this->color2 = color2ToSet; }

	void Render();
};

