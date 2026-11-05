#include "SScreenScene.h"

void SScreenScene::AddGameObject(Solid* object)
{
	this->gameObjects.push_back(object);
}

void SScreenScene::Render()
{
	this->auxCamera->Render();
	for (int idx = 0; idx < gameObjects.size(); idx++) {
		gameObjects[idx]->Render();
	}
	this->swapCameras();
}

void SScreenScene::Update(const float& time) {
	this->p1Camera->Update(time);
	this->p2Camera->Update(time);
	for (int idx = 0; idx < gameObjects.size(); idx++) {
		gameObjects[idx]->Update(time);
	}
	this->checkBoundaries();

}
void SScreenScene::swapCameras() {
	if (auxCamera == p1Camera) {
		this->auxCamera = this->p2Camera;
	}
	else if (auxCamera == p2Camera) {
		this->auxCamera = this->p1Camera;
	}
}

void SScreenScene::checkBoundaries() {
	for (int idx = 0; idx < gameObjects.size(); idx++)
	{
		bool inBoundaries = true;

		if (gameObjects[idx]->GetCoordinates().getX() > this->GetBoundaries().getX() + 1 || gameObjects[idx]->GetCoordinates().getX() < -100)
		{
			inBoundaries = false;
		}
		if (gameObjects[idx]->GetCoordinates().getY() > this->GetBoundaries().getY() + 1 || gameObjects[idx]->GetCoordinates().getY() < -10)
		{
			inBoundaries = false;
		}
		if (gameObjects[idx]->GetCoordinates().getZ() > this->GetBoundaries().getZ() + 1 || gameObjects[idx]->GetCoordinates().getZ() < -100)
		{
			inBoundaries = false;
		}

		if (inBoundaries)
		{

			if (gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0) >= this->GetBoundaries().getX() || gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0) <= -this->GetBoundaries().getX())
			{
				if (gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0) >= this->GetBoundaries().getX())
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ()));
				}
				else if (gameObjects[idx]->GetCoordinates().getX() - (0.1 * 2.0 * 2.0) <= -this->GetBoundaries().getX())
				{
					gameObjects[idx]->SetCoordinates(Vector3D(gameObjects[idx]->GetCoordinates().getX() + (0.1 * 2.0 * 2.0), gameObjects[idx]->GetCoordinates().getY(), gameObjects[idx]->GetCoordinates().getZ()));
				}
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX() * 0, gameObjects[idx]->GetSpeed().getY(), gameObjects[idx]->GetSpeed().getZ()));
				gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() * -1, gameObjects[idx]->GetOrientation().getZ()));
			}
			if (gameObjects[idx]->GetCoordinates().getY() >= this->GetBoundaries().getY() || gameObjects[idx]->GetCoordinates().getY() <= 0)
			{
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX(), gameObjects[idx]->GetSpeed().getY() * 0, gameObjects[idx]->GetSpeed().getZ()));
				//gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() * -1, gameObjects[idx]->GetOrientation().getZ()));
			}
			if (gameObjects[idx]->GetCoordinates().getZ() + (0.1 * 2.0 * 2.0) >= this->GetBoundaries().getZ() || gameObjects[idx]->GetCoordinates().getZ() - (0.1 * 2.0 * 2.0) <= -19.8)
			{
				gameObjects[idx]->SetSpeed(Vector3D(gameObjects[idx]->GetSpeed().getX(), gameObjects[idx]->GetSpeed().getY(), gameObjects[idx]->GetSpeed().getZ() * 0));
				gameObjects[idx]->SetOrientation(Vector3D(gameObjects[idx]->GetOrientation().getX(), gameObjects[idx]->GetOrientation().getY() + 180, gameObjects[idx]->GetOrientation().getZ()));
				if (gameObjects[idx]->GetCoordinates().getZ() + (0.1 * 2.0 * 2.0) >= this->GetBoundaries().getX())
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

