#pragma once
#include "Solid.h"
#include <string>

class Text : public Solid
{
private:
	string innerText;
public:
	Text(string texto) : Solid(Vector3D(-0.5, 0.0, -2.0), Color(0.0, 0.0, 0.0), Vector3D(), Vector3D(), Vector3D()), innerText(texto) {}
	inline string getText() { return innerText; }
	inline void setText(const string& textToSet) { innerText = textToSet; }

	void Render(); 

};

