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


int Attack(int target)
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
		target = target - 10;
	}
	else if (Player1.WeaponSelect == "sword" || Player1.WeaponSelect == "Sword")
	{
		sword = Player1.SwordWeaponUse(sword, Player1.WeaponSelect);
		target = target -15;
	}
	cout << "bow uses left: " << bow << endl;
	cout << "sword uses left: " << sword << endl;

	cout << endl;

	return target;
}

void Battle(int target)
{
	
	cout << "your walking down a dark path when a bear attackes you" << endl;
	while (target > 0)
	{
		cout << "bears health: " << target << endl;
		cout << endl;
		target = Attack(target);
	}
	if (target <= 0)
	{
		cout << "you have killed the bear." << endl;
	}
}

void MainGame(int Health, int target)
{
	cout << endl;
	cout << endl;

	cout << "Current Health " << Health << endl;
	if (Health == 0)
	{
		cout << "Game Over" << endl;
		cout << "You have died" << endl;
	}
	else if (Health > 0)
	{
		Battle(target);
	}

}

void SaveGame(int health, int target)
{
	gamesaveOUT.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	gamesaveOUT << "current_health: " << health << endl;
	cout << "Game Saved" << endl;

	gamesaveOUT << "targets_current_health: " << target << endl;

	gamesaveOUT.close();
}

int LoadGame()
{
	
	string HealthText;
	int Health;

	gamesaveIN.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	if(gamesaveIN.is_open() == true)
	{
		cout << "game loaded" << endl;
	
		gamesaveIN >> HealthText;
		cout << HealthText << " ";

		gamesaveIN >> Health;
		cout << Health << endl;

		gamesaveIN.close();
	}
	else
	{
		cout << "Unable to load game save" << endl;
	}
	return Health;
}

int MainMenu(int target)
{
	int LoadOption;
	int Health;
	cout << "	Welcome to the Main Menu	" << endl;
	cout << endl;
	
	cout << "1: Load Game" << endl;
	cout << "2: New Game" << endl;
	cout << endl;

	cout << "Enter: ";
	cin >> LoadOption;
	cout << endl;

	if (LoadOption == 1)
	{
		Health = LoadGame();
	}
	else if (LoadOption == 2)
	{
		Health = 100;
		target = 150;
		SaveGame(Health, target);
	}
	return Health;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int health;
	int target;

	health = MainMenu(target);
	
	MainGame(health,target);
	

	//SaveGame(health);
	return 0;
}

