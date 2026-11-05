#include "Cube.h"

void Cube::Render()
{
	glPushMatrix();
	glTranslatef(this->Cube::GetCoordinates().getX(), this->Cube::GetCoordinates().getY(), this->Cube::GetCoordinates().getZ());
	glColor3f(this->Cube::GetColor().getRed(), this->Cube::GetColor().getGreen(), this->Cube::GetColor().getBlue());
	glRotatef(this->Cube::GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->Cube::GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->Cube::GetOrientation().getZ(), 0.0, 0.0, 1.0);
	glutSolidCube(this->GetSize());
	glPopMatrix();
}
