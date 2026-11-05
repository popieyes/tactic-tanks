#include "Sphere.h"

void Sphere::Render()
{
	glPushMatrix();
	glTranslatef(this->Sphere::GetCoordinates().getX(), this->Sphere::GetCoordinates().getY(), this->Sphere::GetCoordinates().getZ());
	glColor3f(this->Sphere::GetColor().getRed(), this->Sphere::GetColor().getGreen(), this->Sphere::GetColor().getBlue());
	glRotatef(this->Sphere::GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->Sphere::GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->Sphere::GetOrientation().getZ(), 0.0, 0.0, 1.0);
	glutSolidSphere(this->GetRadius(), this->GetSlices(), this->GetSlacks());
	glPopMatrix();
}
