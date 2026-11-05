#pragma once
#include "Text.h"
#include "Player.h"
#include <vector>
class HUD
{
private:
	Player* player;
	Text playerLives;
	Text playerHealth;
	Text playerStatus;
	Text win;

	void setHUDPosition();

public:
	HUD(Player* player) : playerLives("Lives: " + to_string(player->getLives())), playerHealth("Health: " + to_string(player->getHealth())), playerStatus("Sistemas operativos"), win("Partida en curso..."), player(player) {}

	inline Text getLivesText() const { return playerLives; }
	inline void setLivesText(const Text textToSet) { playerLives = textToSet; }
	inline Text getHealthText() const { return playerHealth; }
	inline void setHealthText(const Text textToSet) { playerHealth = textToSet; }
	inline Text getStatusText() const { return playerStatus; }
	inline void setStatusText(const Text textToSet) { playerStatus = textToSet; }
	inline Text getWinText() const { return win; }
	inline void setWinText(const Text textToSet) { win = textToSet; }

	void Render();
	void Update();
};

