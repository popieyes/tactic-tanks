#include "Game.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI/180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0/ M_PI)

void Game::ProcessKeyPressed(unsigned char key, int px, int py) 
{
	// de momento no hacemos nada...
	//std::cout << "Tecla pulsada: " << key << std::endl;
	float rotacion = player->getOrientation().getY();
	float rotacion2 = player2->getOrientation().getY();
	if (playing) {
		switch (key)
		{
		case 'w':
		case 'W':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.025);
			break;
		case 's':
		case 'S':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * -0.025);
			break;
		case 'a':
		case 'A':
			rotacion += 10;
			player->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player->getOrientationSpeed().getX(),
					0.3,
					this->player->getOrientationSpeed().getZ()
				));
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00);

			break;
		case 'd':
		case 'D':
			rotacion -= 10;
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00);
			this->player->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player->getOrientationSpeed().getX(),
					-0.3,
					this->player->getOrientationSpeed().getZ()
				));

			break;
		case 'e':
		case 'E':
			if (shootAgain)
			{
				bullet->SetCoordinates(Vector3D(player->getCoordinates().getX() - 0.3, player->getCoordinates().getY() + 5.0, player->getCoordinates().getZ()));
				bullet->SetOrientation(Vector3D(0.0, rotacion, 0.0));
				bullet->SetSpeed(this->calcSpeedVector(rotacion) * 0.05);
				//playerModel->SetOrientation(Vector3D(0.0, rotacion, 0.0));
			}
			break;
		case 'p':
		case 'P':
			if (shootAgain2)
			{
				bullet2->SetCoordinates(Vector3D(player2->getCoordinates().getX() + 0.3, player2->getCoordinates().getY() + 5.0, player2->getCoordinates().getZ()));
				bullet2->SetOrientation(Vector3D(0.0, rotacion2, 0.0));
				bullet2->SetSpeed(this->calcSpeedVector(rotacion2) * 0.05);
			}
			break;
		}
	}
	
	this->menuScene->ProcessKeyPressed(key,px,py);
}

void Game::ProcessSpecialKeyPressed(unsigned char key, int px, int py) {
	float rotacion2 = player2->getOrientation().getY();
	if (playing) {
		switch (key)
		{
		case GLUT_KEY_UP:
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.025);
			break;
		case GLUT_KEY_DOWN:

			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * -0.025);
			break;
		case GLUT_KEY_RIGHT:
			rotacion2 -= 10;
			this->player2->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player2->getOrientationSpeed().getX(),
					-0.3,
					this->player2->getOrientationSpeed().getZ()
				));
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00);

			break;
		case GLUT_KEY_LEFT:

			rotacion2 += 10;
			this->player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00);
			this->player2->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player2->getOrientationSpeed().getX(),
					+0.3,
					this->player2->getOrientationSpeed().getZ()
				));

			break;

		}
	}

}

void Game::ProcessSpecialKeyUp(unsigned char key, int px, int py) {
	float rotacion2 = player2->getModel()->GetOrientation().getY();
	if (playing) {
		switch (key) {
		case GLUT_KEY_UP:
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00); // Cuando se deje de pulsar el botón de avanzar, queremos que el tanque no siga avanzando
			break;
		case GLUT_KEY_DOWN:
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00);
			break;
		case GLUT_KEY_LEFT:
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00);
			this->player2->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player2->getOrientationSpeed().getX(),
					0.0,
					this->player2->getOrientationSpeed().getZ()
				));
			break;

		case GLUT_KEY_RIGHT:
			player2->getModel()->SetSpeed(this->calcSpeedVector(rotacion2) * 0.00);
			this->player2->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player2->getOrientationSpeed().getX(),
					0.0,
					this->player2->getOrientationSpeed().getZ()
				));
			break;
		}
	}
	
}

void Game::ProcessKeyUp(unsigned char key, int px, int py)
{
	// Mostramos que tecla se deja de pulsar
	//std::cout << "Tecla pulsada: " << key << std::endl;
	//Implementamos las instucciones que queremos que sucedan al dejar de pulsar cada tecla
	float rotacion = player->getModel()->GetOrientation().getY();
	if (playing) {
		switch (key)
		{
		case 'w':
		case 'W':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00); // Cuando se deje de pulsar el botón de avanzar, queremos que el tanque no siga avanzando
			break;
		case 's':
		case 'S':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00);
			break;

		case 'a':
		case 'A':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00);
			this->player->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player->getOrientationSpeed().getX(),
					0.0,
					this->player->getOrientationSpeed().getZ()
				));
			break;
		case 'd':
		case 'D':
			player->getModel()->SetSpeed(this->calcSpeedVector(rotacion) * 0.00);
			this->player->getModel()->SetOrientationSpeed(
				Vector3D(
					this->player->getOrientationSpeed().getX(),
					0.0,
					this->player->getOrientationSpeed().getZ()
				));
			break;
		}
	}
	
}

Vector3D Game::calcSpeedVector(float orientation) {
	float ydeg = orientation;

	float yOrientation = degToRad(orientation);

	//Flying camera
	//float xComponent = sin(yOrientation) * cos(xOrientation);
	//float yComponent = -sin(xOrientation);
	//float zComponent = -cos(yOrientation) * cos(xOrientation);

	//Walking camera
	float xComponent = sin(yOrientation);
	float yComponent = 0;
	float zComponent = -cos(yOrientation);

	Vector3D speedVector = { -xComponent, yComponent, zComponent };
	return speedVector;
}

void Game::ProcessMouseMovement(int x, int y)
{
	//std::cout << "Movimiento del mouse: " << x << ", " << y << std::endl;
	this->menuScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y) 
{
	// de momento no hacemos nada...
	//std::cout << "Clic: " << button << std::endl;
	if (((button == 1) || (button==2))&&(activeScene == menuScene))
	{
		pulsado = true;
	}
}

void Game::Init() 
{
	ModelLoader* loader = new ModelLoader();
	// Cada vez que se inicializa, se puede volver a disparar
	shootAgain = true;
	shootAgain2 = true;
	playing = true;
	//Creación del Cuboid que actúa como suelo
	Cuboid* cuboid = new Cuboid();
	
	cuboid->SetCoordinates(Vector3D(0.0, -1.0, 0.0));
	cuboid->SetOrientation(Vector3D(0.0, 0.0, 90.0));
	cuboid->SetHeight(43);
	cuboid->SetWidth(43);
	cuboid->SetColor(Color(0.5, 0.4, 0.4));

	
	//Asignación de Modelos
	
	//Tanques Menú
	this->menuTank1 = new Model();
	this->menuTank2 = new Model();

	//Jugador 1
	this->playerModelAssigner = new Model();
	loader->SetScale(0.6);
	loader->LoadModel("../tank.obj");
	*this->playerModelAssigner = loader->GetModel();
	*this->menuTank1 = loader->GetModel();
	*this->menuTank2 = loader->GetModel();
	this->player = new Player(playerModelAssigner);

	//Jugador 2
	this->playerModelAssigner = new Model();
	*this->playerModelAssigner = loader->GetModel();
	this->player2 = new Player(playerModelAssigner);
	loader->Clear();

	
	
	//Escenario

	escenario = new Model();
	loader->SetScale(0.3);
	loader->LoadModel("../castle4.obj");
	*escenario = loader->GetModel();
	*escenario = loader->GetModel();
	escenario->SetCoordinates(Vector3D(0.0, 3.0, 0.0));
	loader->Clear();

	//Misil

	bullet = new Model();
	bullet2 = new Model();
	loader->SetScale(0.05);
	loader->LoadModel("../misil.obj");
	*bullet = loader->GetModel();
	*bullet2 = loader->GetModel();
	loader->Clear();
	bullet->PaintColor(Color(0.97, 0, 0));
	bullet2->PaintColor(Color(0.97, 0, 0));

	//Título

	Model* title = new Model();
	loader->SetScale(3.3);
	loader->LoadModel("../title.obj");
	*title = loader->GetModel();
	title->SetCoordinates(Vector3D(0.5, 7.0, 0.0));
	title->PaintColor(Color(0.0, 0.0, 0.8));
	title->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	loader->Clear();

	//Texto Jugar
	
	jugar = new Model();
	loader->SetScale(3.5);
	loader->LoadModel("../jugar.obj");
	*jugar = loader->GetModel();
	loader->Clear();
	jugar->SetCoordinates(Vector3D(5, -2.0, 0.0));
	jugar->PaintColor(Color(0.5, 0.5, 0.6));
	jugar->SetOrientation(Vector3D(70.0, 0.0, 0.0));

	//Cámaras en tercera persona
	tCamera = new ThirdPersonCamera(player, Vector3D(0.0, 1.0, 5.0));
	t2Camera = new ThirdPersonCamera(player2, Vector3D(0.0, 1.0, 5.0));
	
	//Escena pantalla dividida
	inGame = new SScreenScene(tCamera, t2Camera);

	//Áñadir Modelos A Escenas
	//Escena de juego
	inGame->AddGameObject(player->getModel());
	inGame->AddGameObject(player2->getModel());
	inGame->AddGameObject(escenario);
	inGame->AddGameObject(bullet);
	inGame->AddGameObject(bullet2);
	inGame->AddGameObject(cuboid);

	//Escena de menú
	menuScene->AddGameObject(menuTank1);
	menuScene->AddGameObject(menuTank2);
	menuScene->AddGameObject(title);
	menuScene->AddGameObject(jugar);

	//Sets de modelos

	menuTank1->SetCoordinates(Vector3D(0.0, 1.5, 0.0));
	menuTank1->SetOrientation(Vector3D(0.0, -135.0, 0.0));
	menuTank1->PaintColor(Color(0, 1, 0.0));
	menuTank2->SetCoordinates(Vector3D(+9.5, 1.5, 0.0));
	menuTank2->SetOrientation(Vector3D(0.0, +135.0, 0.0));
	menuTank2->PaintColor(Color(1.0, 0.0, 0.0));


	player->getModel()->SetCoordinates(Vector3D(0.0, 0.1, 10.0));
	player->getModel()->PaintColor(Color(0.0, 1, 0.0));

	player2->getModel()->PaintColor(Color(1, 0, 0));
	player2->getModel()->SetCoordinates(Vector3D(0.0, 0.1, -10.0));
	player2->getModel()->SetOrientation(Vector3D(0.0, 180, 0.0));

	bullet->SetCoordinates(Vector3D(50.0, -20.0, 50.0));
	bullet2->SetCoordinates(Vector3D(50.0, -20.0, 50.0));
	
	//Añadir escenas a vector de escenas
	this->scenes.push_back(inGame);
	this->scenes.push_back(menuScene);
	
	//Condición de escenas (Si no se ha hecho click, seguimos en la escena del menú)
	if (pulsado == 0) {
		this->activeScene = this->scenes.back();
	}
	else {
		this->scenes.pop_back();
		this->activeScene = this->scenes.back();
	}
	
	
}

void Game::Render() 
{
	
	this->activeScene->Render();
	


}

void Game::Update() 
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{	
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
	}

	//Detección de colisiones de misiles con tanques
	if ((bullet->GetCoordinates().getX() >= player2->getCoordinates().getX() - 1.5 && bullet->GetCoordinates().getX() <= player2->getCoordinates().getX() + 1.5) && (bullet->GetCoordinates().getZ() >= player2->getCoordinates().getZ() - 1.2 && bullet->GetCoordinates().getZ() <= player2->getCoordinates().getZ() + 1.2))
	{
		shootAgain = true;
		bullet->SetCoordinates(Vector3D(50.0, 20.0, 50.0));
		player2->setHealth(player2->getHealth() - 60);
	}
	if ((bullet2->GetCoordinates().getX() >= player->getCoordinates().getX() - 1.5 && bullet2->GetCoordinates().getX() <= player->getCoordinates().getX() + 1.5) && (bullet2->GetCoordinates().getZ() >= player->getCoordinates().getZ() - 1.2 && bullet2->GetCoordinates().getZ() <= player->getCoordinates().getZ() + 1.2))
	{
		shootAgain2 = true;
		bullet2->SetCoordinates(Vector3D(50.0, 20.0, 50.0));
		player->setHealth(player->getHealth() - 60);
	}

	//Detección de colisiones de misiles con paredes
	if ((this->bullet->GetCoordinates().getX() >= this->activeScene->GetBoundaries().getX() - 0.5 || 
		this->bullet->GetCoordinates().getX() <= -this->activeScene->GetBoundaries().getX() + 0.5) || 
		(this->bullet->GetCoordinates().getZ() >= this->activeScene->GetBoundaries().getZ() - 0.5 || 
		this->bullet->GetCoordinates().getZ() <= -this->activeScene->GetBoundaries().getZ() + 1.0))
	{
		shootAgain = true;
		bullet->SetCoordinates(Vector3D(-50.0, -20.0, -50.0));
	}
	else
	{
		shootAgain = false;
	}

	if ((this->bullet2->GetCoordinates().getX() >= this->activeScene->GetBoundaries().getX() - 0.5 ||
		this->bullet2->GetCoordinates().getX() <= -this->activeScene->GetBoundaries().getX() + 0.5) ||
		(this->bullet2->GetCoordinates().getZ() >= this->activeScene->GetBoundaries().getZ() - 0.5 ||
			this->bullet2->GetCoordinates().getZ() <= -this->activeScene->GetBoundaries().getZ() + 1.0))
	{
		shootAgain2 = true;
		bullet2->SetCoordinates(Vector3D(-50.0, -20.0, -50.0));
	}
	else
	{
		shootAgain2 = false;
	}
	
	//Cambio de escenas
	if (pulsado == 0)
	{
		this->activeScene = this->menuScene;
	}
	else
	{
		this->activeScene = this->inGame;
	}

	//Pausado de juego
	if (player->getLives() == 0 || player2->getLives() == 0) {
		if (player->getLives() == 0) {
			player2->setHealth(69);
		}
		else if (player2->getLives() == 0) {
			player->setHealth(69);
		}
		playing = false;
	}
};











