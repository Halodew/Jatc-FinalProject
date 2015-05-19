// FinalProject_TextBasedAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Weapons.h"
#include "Player.h"
using namespace std;

ifstream gamesaveIN ("C:/Users/duehlste001/Documents/Visual Studio 2013/Projects/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
ofstream gamesaveOUT; //("C:/Users/duehlste001/Documents/Visual Studio 2013/Projects/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");




void Attack()
{
	Player Player1;
	int sword = 15;
	int bow = 20;


	cout << "Select Weapon: ";
	cin >> Player1.WeaponSelect;
	Player1.ZeroWeaponUse(sword, bow);

	if (Player1.WeaponSelect == "bow" || Player1.WeaponSelect == "Bow")
	{
		bow = Player1.BowWeaponUse(bow, Player1.WeaponSelect);
	}
	else if (Player1.WeaponSelect == "sword" || Player1.WeaponSelect == "Sword")
	{
		sword = Player1.SwordWeaponUse(sword, Player1.WeaponSelect);
	}
	cout << bow << endl;
	cout << sword << endl;

	cout << endl;
}

void gamesave(int health)
{
	gamesaveOUT.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	gamesaveOUT << "current health: " << health;
	cout << health << endl;
	gamesaveOUT.close();
}

int LoadGame()
{
	int health = 100;
	string health1;
	int health2;
	gamesaveIN.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	if(gamesaveIN.is_open() == true)
	{
		cout << "game loaded" << endl;
		cout << health << endl;
		gamesaveIN >> health1;
		cout << health1 << " ";

		gamesaveIN >> health2;
		cout << health2 << endl;
	}
	else
	{
		cout << "Unable to load game save" << endl;
	}
	return health;
}

void MainMenu()
{
	int LoadOption;
	cout << "	Welcome to the Main Menu	" << endl;
	cout << endl;
	cout << "1: Load Game" << endl;
	cout << "2: New Game" << endl;
	cin >> LoadOption;

	if (LoadOption == 1)
	{
		LoadGame();
	}
	else if (LoadOption == 2)
	{
		cout << "test2" << endl;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int health = 10;

	MainMenu();

	//gamesave(health);
	return 0;
}

