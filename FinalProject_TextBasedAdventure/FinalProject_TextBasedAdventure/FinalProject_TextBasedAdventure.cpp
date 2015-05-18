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

void gamesave()
{
	int health = 100;
	gamesaveOUT.open("C:/Users/duehlste001/Documents/Visual Studio 2013/Projects/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	gamesaveOUT;
}


int _tmain(int argc, _TCHAR* argv[])
{
	gamesave();
	return 0;
}

