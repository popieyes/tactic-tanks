#pragma once
class Color
{
private:
	float RedComponent;
	float GreenComponent;
	float BlueComponent;

public:
	Color() : RedComponent(1.0), GreenComponent(1.0), BlueComponent(1.0) {}
	Color(float r, float g, float b) : RedComponent(r), GreenComponent(g), BlueComponent(b) {}

	inline float getRed() { return this->RedComponent; }
	inline float getGreen() { return this->GreenComponent; }
	inline float getBlue() { return this->BlueComponent; }

	void SetRedComponent(const float& redComponentToSet);
	void SetGreenComponent(const float& greenComponentToSet);
	void SetBlueComponent(const float& blueComponentToSet);

};

