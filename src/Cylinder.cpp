#include "Cylinder.h"

void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(this->GetCoordinates().getX(), this->GetCoordinates().getY(), this->GetCoordinates().getZ());
	glColor3f(this->GetColor().getRed(), this->GetColor().getGreen(), this->GetColor().getBlue());
	glRotatef(this->GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().getZ(), 0.0, 0.0, 1.0);
	gluCylinder(quadricTemp, this->GetBaseRadius(), this->GetTopRadius(), this->GetHeight(), this->GetSlices(), this->GetStacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);
}
