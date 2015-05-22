// FinalProject_TextBasedAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
//#include <fstream>
//#include <iostream>
#include "Weapons.h"
#include "Player.h"
#include "game.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Player player1;
	game game1;
	int health = player1.getHealth();
	int target = player1.gettargetHealth();
	int bow = player1.getbow();
	int sword = player1.getsword();

	 game1.MainMenu(target);
	
	game1.MainGame(health,target,bow,sword);

	return 0;
}

