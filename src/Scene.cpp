#include "Scene.h"

void Scene::AddGameObject(Solid* object) {
	gameObjects.push_back(object);
}

void Scene::Render() {

	this->camera->Render();
	for (int idx = 0; idx < gameObjects.size(); idx++) {
		gameObjects[idx]->Render();
	}
}


void Scene::checkBoundary()
{
	for (int idx = 0; idx < gameObjects.size(); idx++)
	{
		bool inBoundaries = true;

		if (gameObjects[idx]->GetCoordinates().getX() > boundary.getX() + 1 || gameObjects[idx]->GetCoordinates().getX() < -100)
		{
			inBoundaries = false;
		}
		if (gameObjects[idx]->GetCoordinates().getY() > boundary.getY() + 1 || gameObjects[idx]->GetCoordinates().getY() < -10)
		{
			inBoundaries = false;
		}
		if (gameObjects[idx]->GetCoordinates().getZ() > boundary.getZ() + 1 || gameObjects[idx]->GetCoordinates().getZ() < -100)
		{
			inBoundaries = false;
		}

		if (inBoundaries)
		{

			if (gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0) >= boundary.getX() || gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0) <= -boundary.getX())
			{
				if (gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0) >= boundary.getX())
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ()));
				}
				else if (gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0) <= -boundary.getX())
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ()));
				}
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX() * 0, gameObjects[idx]->GetSpeed().getY(), gameObjects[idx]->GetSpeed().getZ()));
				gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() * -1, gameObjects[idx]->GetOrientation().getZ()));
			}
			if (gameObjects[idx]->GetCoordinates().getY() >= boundary.getY() || gameObjects[idx]->GetCoordinates().getY() <= 0)
			{
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX(), gameObjects[idx]->GetSpeed().getY() * 0, gameObjects[idx]->GetSpeed().getZ()));
				//gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() * -1, gameObjects[idx]->GetOrientation().getZ()));
			}
			if (gameObjects[idx]->GetCoordinates().getZ() + (0.1 * 2.0 * 2.0) >= boundary.getZ() || gameObjects[idx]->GetCoordinates().getZ() - (0.1 * 2.0 * 2.0) <= -19.8)
			{
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX(), gameObjects[idx]->GetSpeed().getY(), gameObjects[idx]->GetSpeed().getZ() * 0));
				gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() + 180, gameObjects[idx]->GetOrientation().getZ()));
				if (gameObjects[idx]->GetCoordinates().getZ() + (0.1 * 2.0 * 2.0) >= boundary.getX())
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX(), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ() - (0.1 * 2.0 * 2.0)));
				}
				else if (gameObjects[idx]->GetCoordinates().getZ() - (0.1 * 2.0 * 2.0) <= -19.8)
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX(), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ() + (0.1 * 2.0 * 2.0)));
				}
				if (gameObjects[idx]->GetOrientation().getY() - 90 == 0)
				{
					gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() + 180, gameObjects[idx]->GetOrientation().getZ()));
				}
				else if (gameObjects[idx]->GetOrientation().getY() + 90 == 180)
				{
					gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() - 180, gameObjects[idx]->GetOrientation().getZ()));
				}
				else
				{
					gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() * -1, gameObjects[idx]->GetOrientation().getZ()));
				}

			}
		}
	}
}

void Scene::Update(const float& time) {

	for (int idx = 0; idx < gameObjects.size(); idx++) {
		gameObjects[idx]->Update(time);

	}
	this->checkBoundary();
}

void Scene::ProcessMouseMovement(int x, int y) {
	this->camera->ProcessMouseMovement(x,y);
}
void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {
	this->camera->ProcessKeyPressed(key, px, py);
}
