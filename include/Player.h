#pragma once
#include "Model.h"
#include "ModelLoader.h"

class Player 
{
private: 
	float health; 
	int lives;
	Model* model;

public:
	Player(Model* modelnew) : health(100), model(modelnew), lives(3) {}

	inline float getHealth() const { return health;  }
	inline void setHealth(const float newHealth) { health = newHealth; }

	inline int getLives() const { return lives; }
	inline void setLives(const int newLives) { lives = newLives;}

	inline Model* getModel() { return model; }
	inline void setModel( Model* newModel) { model = newModel; }

	inline Vector3D getOrientation() { return model->GetOrientation(); }
	inline Vector3D getCoordinates() { return model->GetCoordinates(); }
	inline Vector3D getOrientationSpeed() { return model->GetOrientationSpeed(); }
	inline Vector3D getSpeed() { return model->GetSpeed(); }

	void Update();
};

