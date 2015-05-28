#ifndef GAME_H
#define GAME_H

#include "stdafx.h"
#include <fstream>

class game
{
public:
	void MainMenu(int target);
	void MainGame(int Health, int target, int& bow, int& sword);
	void LoadGame();
	void SaveGame(int& health, int& target, int& bow, int& sword);
	int Attack(int target, int& bow, int& sword);
	void Battle(int target, int& bow, int& sword);

	std::ifstream gamesaveIN;
	std::ofstream gamesaveOUT;
};

#endif