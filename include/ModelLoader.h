#pragma once
#include "Model.h"
#include <sstream>
#include <fstream>
class ModelLoader
{
private:
	float scale = 0.3;
	Model model;
	vector <Vector3D> vertexes;
	vector <Vector3D> normals;
	float minX;
	float minY;
	float minZ;
	float maxX;
	float maxY;
	float maxZ;

	inline float getWidth() const { return maxX-minX; };
	inline float getHeight() const { return maxY-minY; }
	inline float getLength() const { return maxZ-minZ; }
	void calcBoundaries(Vector3D vectorPoint);
	Triangle center(Triangle triangle);
	Vector3D parseObjLineToVector3D(const string& line);
	Triangle parseObjTriangle(const string& line);

public:
	inline Model GetModel() { return model; }
	inline float GetScale() { return scale; }


	inline void SetScale(const float& scaleToSet) { scale = scaleToSet; }
	void LoadModel(const string& filePath);
	void Clear();
};

