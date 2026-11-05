#include "Model.h"

void Model::Render() 
{
	glPushMatrix();
	glTranslatef(this->GetCoordinates().getX(), this->GetCoordinates().getY(), this->GetCoordinates().getZ());
	glColor3f(this->GetColor().getRed(), this->GetColor().getGreen(), this->GetColor().getBlue());
	glRotatef(this->GetOrientation().getX(), 1.0, 0.0, 0.0);
	glRotatef(this->GetOrientation().getY(), 0.0, 1.0, 0.0);
	glRotatef(this->GetOrientation().getZ(), 0.0, 0.0, 1.0);
	//Por cada(Triangulo t en triángulos) t.Render();
	for (int idx = 0; idx < triangles.size(); idx++) {
		triangles[idx].Render();
	}
	/*
	for (Triangle& t : triangles) {
		t.Render();
	}
	*/
	glPopMatrix();
}

void Model::AddTriangle(Triangle triangle) {
	triangles.push_back(triangle);
}

void Model::PaintColor(Color color) {
	for (Triangle& triangle : this->triangles)
	{
		triangle.SetColor0(color);
		triangle.SetColor1(color);
		triangle.SetColor2(color);
	}

}

void Model::Clear() {
	triangles.clear();
}