#include "Solid.h"
void Solid::Update(const float& time)
{
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * time);
	this->SetCoordinates(this->GetCoordinates() + this->GetSpeed() * time);
}