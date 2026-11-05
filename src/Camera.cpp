#include "Camera.h"
void Camera::Render() {
	glTranslatef(-1 * this->GetCoordinates().getX(), -1 * this->GetCoordinates().getY(), -1 * this->GetCoordinates().getZ());
	glRotatef(this->GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().getZ(), 0.0, 0.0, 1.0);

}

