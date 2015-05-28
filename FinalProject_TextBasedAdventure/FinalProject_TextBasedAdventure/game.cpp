#include "stdafx.h"
#include <iostream>
//#include <fstream>
#include "Player.h"
#include "game.h"
using namespace std;


//class game
//{
//public:
//	void MainMenu(int target);
//	void MainGame(int Health, int target, int& bow, int& sword);
//};

void game::LoadGame()
{

	//gamesaveIN("C:/Users/duehlste001/Documents/Visual Studio 2013/Projects/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	//gamesaveOUT; //("C:/Users/duehlste001/Documents/Visual Studio 2013/Projects/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");

	Player player1;
	string SaveText;
	int SaveValue;


	gamesaveIN.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");
	if (gamesaveIN.is_open() == true)
	{
		cout << "game loaded" << endl;

		while (!gamesaveIN.eof())
		{
			gamesaveIN >> SaveText;
			gamesaveIN >> SaveValue;
			if (SaveText == "current_health: ")
			{
				player1.setHealth(SaveValue);
			}
			else if (SaveText == "targets_current_health: ")
			{
				player1.setTargetHealth(SaveValue);
			}
			else if (SaveText == "Number_of_bow_uses_left: ")
			{
				player1.setBow(SaveValue);
			}
			else if (SaveText == "Number_of_sword_uses_left: ")
			{
				player1.setSword(SaveValue);
			}
		}
		gamesaveIN.close();
	}
	else
	{
		cout << "Unable to load game save" << endl;
	}

}
void game::SaveGame(int& health, int& target, int& bow, int& sword)
{
	gamesaveOUT.open("C:/Users/duehlste001/Documents/GitHub/Jatc-FinalProject/FinalProject_TextBasedAdventure/FinalProject_TextBasedAdventure/GameSave.txt");

	gamesaveOUT << "current_health: " << health << endl;
	gamesaveOUT << "targets_current_health: " << target << endl;
	gamesaveOUT << "Number_of_bow_uses_left: " << bow << endl;
	gamesaveOUT << "Number_of_sword_uses_left: " << sword << endl;


	cout << "Game Saved" << endl;
	gamesaveOUT.close();
}

void game::MainMenu(int target)
{
	game g;
	Player player1;
	int LoadOption;
	int Health = player1.getHealth();
	target = player1.gettargetHealth();

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
		g.LoadGame();
	}
	else if (LoadOption == 2) //reset stats to defualt.
	{
		player1.setHealth(100);
		player1.setTargetHealth(150);
		player1.setBow(20);
		player1.setSword(15);
		int bow = 20;
		int sword = 15;
		g.SaveGame(Health, target, bow, sword);
	}
	int bow = player1.getbow();
	int sword = player1.getsword();



}

int game::Attack(int target, int& bow, int& sword)
{
	Player Player1;

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
		target = target - 15;
	}
	else if (Player1.WeaponSelect == "save" || Player1.WeaponSelect == "Save") //saves current stats.
	{
		int health = Player1.getHealth();
		SaveGame(health, target, bow, sword);
		MainMenu(target);
	}
	cout << endl;
	cout << "bow uses left: " << bow << endl;
	cout << "sword uses left: " << sword << endl;

	cout << endl;

	return target;
}

void game::Battle(int target, int& bow, int& sword)// starts the battle between player and target. 
{
	//planing on making it change each time to diffent target.

	cout << "your walking down a dark path when a bear attackes you" << endl;
	while (target > 0)
	{
		cout << "bears health: " << target << endl;
		cout << endl;
		target = Attack(target, bow, sword); //remeber to add damage taking from target.

	}
	if (target <= 0)
	{
		cout << "you have killed the bear." << endl;
		system("pause");
		MainMenu(target);
	}
}

void game::MainGame(int Health, int target, int& bow, int& sword)
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
		Battle(target, bow, sword);
	}

}




int Player::BowWeaponUse(int BowUse, std::string WeaponSelect)
{


	if (WeaponSelect == "bow" || WeaponSelect == "Bow")
	{
		BowUse--;
		std::cout << "Bow was used" << std::endl;

	}

	return BowUse;
}
int Player::SwordWeaponUse(int SwordUse, std::string WeaponSelect)
{
	if (WeaponSelect == "sword" || WeaponSelect == "Sword")
	{
		SwordUse--;
		std::cout << "Sword was used" << std::endl;
	}
	return SwordUse;
}
void Player::ZeroWeaponUse(int SwordUse, int BowUse)
{
	std::string ZeroUses = "This Weapon Has no more Uses. please select a differnt weapon.";
	if (SwordUse <= 0)
	{
		std::cout << ZeroUses << std::endl;

	}

	if (BowUse <= 0)
	{
		std::cout << ZeroUses << std::endl;
	}

}


int Player::getHealth()
{
	return Health;
}
int Player::getbow()
{
	return bow;
}
int Player::getsword()
{
	return sword;
}
int Player::gettargetHealth()
{
	return target;
}


void Player::setHealth(int newHealth)
{
	Health = newHealth;
}
void Player::setTargetHealth(int newTargetHealth)
{
	target = newTargetHealth;
}
void Player::setBow(int newBow)
{
	bow = newBow;
}
void Player::setSword(int newSword)
{
	sword = newSword;
}


