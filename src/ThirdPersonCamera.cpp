#include "ThirdPersonCamera.h"

void ThirdPersonCamera::Render()
{
	hud.Render();
	glTranslatef(-1 * this->GetCoordinates().getX(), -1 * this->GetCoordinates().getY(), -1 * this->GetCoordinates().getZ());
	glRotatef(this->GetOrientation().getX(), 1, 0, 0);
	glRotatef(this->GetOrientation().getY(), 0, 1, 0);
	glRotatef(this->GetOrientation().getZ(), 0, 0, 1);
	glTranslatef(-1 * target->GetCoordinates().getX(), -1 * target->GetCoordinates().getY(), -1 * target->GetCoordinates().getZ());
	
}

void ThirdPersonCamera::Update(const float& time)
{
	float yOrientation = degToRad(target->GetOrientation().getY());
	//Walking camera
	float xComponent = sin(yOrientation);
	float yComponent = 0;
	float zComponent = -cos(yOrientation);
	this->SetSpeed(Vector3D(-xComponent, yComponent, zComponent));
	this->SetOrientation(Vector3D(this->GetOrientation().getX(), -target->GetOrientation().getY(), target->GetOrientation().getZ()));
	hud.Update();
}


