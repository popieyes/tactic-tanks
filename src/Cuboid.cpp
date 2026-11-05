#include "Cuboid.h"

void Cuboid::Render()
{
	glPushMatrix();
	glTranslatef(this->GetCoordinates().getX(), this->GetCoordinates().getY(), this->GetCoordinates().getZ());
	glColor3f(this->GetColor().getRed(), this->GetColor().getGreen(), this->GetColor().getBlue());
	glRotatef(this->GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().getZ(), 0.0, 0.0, 1.0);
	glScalef(this->GetLength(), this->GetHeight(), this->GetWidth());
	glutSolidCube(1);
	glPopMatrix();
}
