#include "Color.h"

class Color;

void Color::SetRedComponent(const float& redComponentToSet) 
{ 
	if (redComponentToSet < 0) 
	{
		this->RedComponent = 0;
	}
	else if (redComponentToSet > 1) 
	{
		this->RedComponent = 0;
	}
	else 
	{
		this->RedComponent = redComponentToSet;
	}
}
void Color::SetGreenComponent(const float& greenComponentToSet) 
{ 
	if (greenComponentToSet < 0)
	{
		this->GreenComponent = 0;
	}
	else if (greenComponentToSet > 1)
	{
		this->GreenComponent = 0;
	}
	else
	{
		this->GreenComponent = greenComponentToSet;
	}
}
void Color::SetBlueComponent(const float& blueComponentToSet) 
{ 
	if (blueComponentToSet < 0)
	{
		this->BlueComponent = 0;
	}
	else if (blueComponentToSet > 1)
	{
		this->BlueComponent = 0;
	}
	else
	{
		this->BlueComponent = blueComponentToSet;
	}
}
