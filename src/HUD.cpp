#include "HUD.h"

void HUD::setHUDPosition()
{	
		this->playerLives.SetCoordinates(Vector3D(-0.85, 1.35, -2));
		this->playerHealth.SetCoordinates(Vector3D(-0.3, 0, -2));
		this->playerStatus.SetCoordinates(Vector3D(0.15, 1.35, -2));
		this->win.SetCoordinates(Vector3D(-0.25, 1, -2));
}

void HUD::Render()
{
	this->setHUDPosition();
	this->playerLives.Render();
	this->playerHealth.Render();
	this->playerStatus.Render();
	this->win.Render();

}

void HUD::Update() {
		this->player->Update();
		this->setHealthText(Text("Health: " +to_string(this->player->getHealth())));
		this->setLivesText(Text("Lives: "+to_string(this->player->getLives())));
		if (this->player->getHealth() < 50) {
			this->setStatusText(Text("¡Sistemas en peligro!"));
		}
		else {
			this->setStatusText(Text("Sistemas operativos"));
		}

		if (this->player->getLives() == 0) {
			this->setWinText(Text("Derrota"));
		}
		else if (this->player->getHealth() == 69) {
			this->setWinText(Text("Winner Winner Chicken Dinner"));
		}

}