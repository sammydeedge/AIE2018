#pragma once

// Class that manages the game, checks rules, keeps stats
class player_data
{
public:
	
	player_data()
	{
		m_livesLeft = 5;
		m_ammoCount = 3;
	}

	int getLives();
	void loseLife();

	int getAmmoCount();
	void setAmmoCount(int ammo);

	bool getRecentFire();
	void setRecentFire(bool status);

	int getTimer();
	void incrementTimer();
	void resetTimer();

protected:
	int m_livesLeft;
	int m_ammoCount;
	bool m_recentFire	= false;
	int m_fireTimer		= 0;
};