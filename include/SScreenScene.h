#pragma once
#include "Scene.h"
#include "ThirdPersonCamera.h"
class SScreenScene : public Scene
{
private:
	vector <Solid*> gameObjects;
	ThirdPersonCamera* p1Camera;
	ThirdPersonCamera* p2Camera;
	Camera* auxCamera;

	void checkBoundaries();
	void swapCameras();

public:
	SScreenScene(ThirdPersonCamera* player1, ThirdPersonCamera* player2) : Scene(),p1Camera(player1),p2Camera(player2), auxCamera(player1) {}

	inline ThirdPersonCamera* getP1Camera() const { return p1Camera; }
	inline void setP1Camera(const ThirdPersonCamera& newCamera) { *p1Camera = newCamera; }

	inline ThirdPersonCamera* getP2Camera() const { return p2Camera; }
	inline void setP2Camera(const ThirdPersonCamera& newCamera) { *p2Camera = newCamera; }

	void AddGameObject(Solid* object);
	void Render();
	void Update(const float& time);
	
};

