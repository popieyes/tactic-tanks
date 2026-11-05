#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Torus.h"
#include "Cylinder.h"
#include <vector>
#include "Scene.h"
#include "Camera.h"
#include "Model.h"
#include "ModelLoader.h"
#include <chrono>
#include "FirstPersonCamera.h"
#include "ThirdPersonCamera.h"
#include "Player.h"
#include "SScreenScene.h"

using namespace std::chrono;

class Game
{
private:
	//Variables de control de actualización
	const double TIME_INCREMENT = 2.0; //ms tiempo en el juego
	const long UPDATE_PERIOD = 10; //ms tiempo en el mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	//Variables de escenas
	vector<Scene*> scenes;
	Scene* activeScene;
	Scene* menuScene = new(nothrow)	Scene();
	SScreenScene* inGame;

	//Variables de modelos
	Model* bullet;
	Model* bullet2;
	Model* jugar;
	Model* playerModelAssigner;
	Model* menuTank1;
	Model* menuTank2;
	Model* escenario;

	//Declaración de cámaras
	ThirdPersonCamera* tCamera;
	ThirdPersonCamera* t2Camera;
	Player* player;
	Player* player2;

	//Variables booleanas
	bool shootAgain;
	bool shootAgain2;
	bool pulsado;
	bool playing;

	Vector3D calcSpeedVector(float orientation);
public:
	Game() : activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0), 
		playerModelAssigner(nullptr), player(nullptr), tCamera(nullptr), t2Camera(nullptr), escenario(nullptr) {}

	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyUp(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
	void ProcessSpecialKeyPressed(unsigned char key, int px, int py);
	void ProcessSpecialKeyUp(unsigned char key, int px, int py);
	
};

