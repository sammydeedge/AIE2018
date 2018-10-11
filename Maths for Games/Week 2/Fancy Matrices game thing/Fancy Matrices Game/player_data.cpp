#include "player_data.h"

int player_data::getLives()
{
	return m_livesLeft;
}

void player_data::loseLife()
{
	m_livesLeft--;
}

int player_data::getAmmoCount()
{
	return m_ammoCount;
}

void player_data::setAmmoCount(int ammo)
{
	m_ammoCount = ammo;
}

bool player_data::getRecentFire()
{
	return m_recentFire;
}

void player_data::setRecentFire(bool status)
{
	m_recentFire = status;
}

int  player_data::getTimer()
{
	return m_fireTimer;
}

void player_data::incrementTimer()
{
	m_fireTimer++;
}

void player_data::resetTimer()
{
	m_fireTimer = 0;
}