#include "Player.h"

void Player::Update() {

	if (this->getHealth() <= 0 && this->getLives()>1) {
		this->setHealth(100);
		this->setLives(this->getLives() - 1);
	} else if (this->getHealth() <= 0 && this->getLives() == 1) {
		this->setLives(this->getLives() - 1);
	}
	
	
}
