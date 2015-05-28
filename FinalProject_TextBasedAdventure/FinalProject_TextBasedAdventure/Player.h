#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
//using namespace std;
class Player
{
public:
	int BowWeaponUse(int BowUse, std::string WeaponSelect);
	int SwordWeaponUse(int SwordUse, std::string WeaponSelect);
	void ZeroWeaponUse(int SwordUse, int BowUse);

	std::string WeaponSelect;
	

	int getHealth();
	int gettargetHealth();
	int getbow();
	int getsword();

	void setHealth(int newHealth);
	void setTargetHealth(int newTargetHealth);
	void setBow(int newBow);
	void setSword(int newSword);
private:
	int Health = 100;
	int bow = 20;
	int sword = 15;
	int target = 150;
	
	
};

//int Player::BowWeaponUse(int BowUse, std::string WeaponSelect)
//{
//
//	
//	if (WeaponSelect == "bow" || WeaponSelect == "Bow")
//	{
//		BowUse--;
//		std::cout << "Bow was used" << std::endl;
//		
//	}
//
//	return BowUse;
//}
//int Player::SwordWeaponUse(int SwordUse, std::string WeaponSelect)
//{
//	if (WeaponSelect == "sword" || WeaponSelect == "Sword")
//	{
//		SwordUse--;
//		std::cout << "Sword was used" << std::endl;
//	}
//	return SwordUse;
//}
//void Player::ZeroWeaponUse(int SwordUse, int BowUse)
//{
//	std::string ZeroUses = "This Weapon Has no more Uses. please select a differnt weapon.";
//	if (SwordUse <= 0)
//	{
//		std::cout << ZeroUses << std::endl;
//		
//	}
//
//	if (BowUse <= 0)
//	{
//		std::cout << ZeroUses << std::endl;
//	}
//
//}
//
//
//int Player::getHealth()
//{
//	return Health;
//}
//int Player::getbow()
//{
//	return bow;
//}
//int Player::getsword()
//{
//	return sword;
//}
//int Player::gettargetHealth()
//{
//	return target;
//}
//
//
//void Player::setHealth(int newHealth)
//{
//	Health = newHealth;
//}
//void Player::setTargetHealth(int newTargetHealth)
//{
//	target = newTargetHealth;
//}
//void Player::setBow(int newBow)
//{
//	bow = newBow;
//}
//void Player::setSword(int newSword)
//{
//	sword = newSword;
//}

#endif