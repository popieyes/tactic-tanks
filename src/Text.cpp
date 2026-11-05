#include "Text.h"

void Text::Render() {
	glPushMatrix();
	glColor3f(this->GetColor().getRed(), this->GetColor().getGreen(), this->GetColor().getBlue());
	glTranslatef(this->GetCoordinates().getX(), this->GetCoordinates().getY(), this->GetCoordinates().getZ());
	glRasterPos3d(0, 0, 0);
	for (char c : innerText) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);

	}
	glPopMatrix();
}