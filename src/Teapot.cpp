#include "Teapot.h"

void Teapot::Render() 
{
	glPushMatrix();
	glTranslatef(this->Teapot::GetCoordinates().getX(), this->Teapot::GetCoordinates().getY(), this->Teapot::GetCoordinates().getZ());
	glColor3f(this->Teapot::GetColor().getRed(), this->Teapot::GetColor().getGreen(), this->Teapot::GetColor().getBlue());
	glRotatef(GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().getZ(), 0.0, 0.0, 1.0);
	glutSolidTeapot(this->GetSize());
	glPopMatrix();
}

