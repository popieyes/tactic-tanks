#pragma once
#include <vector>
#include "Solid.h"
#include "FirstPersonCamera.h"
#include "Camera.h"

class Scene
{
private:
	vector <Solid*> gameObjects;
	Vector3D boundary;
	FirstPersonCamera* camera = new FirstPersonCamera(Vector3D(5.0, 2.0, 14.0));
	void checkBoundary();

public:
	Scene() : boundary(20.1, 40, 20.2) {}

	
	inline Vector3D GetBoundaries() const { return boundary; }
	inline void SetBoundaries(const Vector3D& boundariesToSet) { boundary = boundariesToSet; }

	virtual void AddGameObject (Solid* object);
	virtual void Render();
	virtual void Update(const float& time);
	void ProcessMouseMovement(int x, int y);
	void ProcessKeyPressed(unsigned char key, int px, int py);
};

