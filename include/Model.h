#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>
class Model : public Solid
{
private:
	vector<Triangle> triangles;
public:
	Model(): Solid() {}

	void AddTriangle(Triangle triangle);
	void PaintColor(Color color);
	void Clear();
	void Render();
};

