#include "Triangle.h"

void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(this->GetColor0().getRed(),this->GetColor0().getGreen(),this->GetColor0().getBlue());
	glNormal3f(this->GetNormal0().getX(),this->GetNormal0().getY(),this->GetNormal0().getZ());
	glVertex3f(this->GetVertex0().getX(),this->GetVertex0().getY(),this->GetVertex0().getZ());
	//vértice 2
	glColor3f(this->GetColor1().getRed(), this->GetColor1().getGreen(), this->GetColor1().getBlue());
	glNormal3f(this->GetNormal1().getX(), this->GetNormal1().getY(), this->GetNormal1().getZ());
	glVertex3f(this->GetVertex1().getX(), this->GetVertex1().getY(), this->GetVertex1().getZ());
	//vértice 3
	glColor3f(this->GetColor2().getRed(), this->GetColor2().getGreen(), this->GetColor2().getBlue());
	glNormal3f(this->GetNormal2().getX(), this->GetNormal2().getY(), this->GetNormal2().getZ());
	glVertex3f(this->GetVertex2().getX(), this->GetVertex2().getY(), this->GetVertex2().getZ());

	glEnd();
}