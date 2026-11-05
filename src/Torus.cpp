#include "Torus.h"

void Torus::Render()
{
	glPushMatrix();
	glTranslatef(this->GetCoordinates().getX(), this->GetCoordinates().getY(), this->GetCoordinates().getZ());
	glColor3f(this->GetColor().getRed(), this->GetColor().getGreen(), this->GetColor().getBlue());
	glRotatef(this->GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().getZ(), 0.0, 0.0, 1.0);
	glutSolidTorus(this->GetIntRadius(),this->GetExtRadius(),this->GetFaces(),this->GetRings());
	glPopMatrix();
}
