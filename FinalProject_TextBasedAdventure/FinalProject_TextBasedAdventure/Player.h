#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
	int BowWeaponUse(int BowUse, string WeaponSelect);
	int SwordWeaponUse(int SwordUse, string WeaponSelect);
	void ZeroWeaponUse(int SwordUse, int BowUse);

	string WeaponSelect;
	

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

int Player::BowWeaponUse(int BowUse, string WeaponSelect)
{

	
	if (WeaponSelect == "bow" || WeaponSelect == "Bow")
	{
		BowUse--;
		cout << "Bow was used" << endl;
		
	}

	return BowUse;
}

int Player::SwordWeaponUse(int SwordUse, string WeaponSelect)
{
	if (WeaponSelect == "sword" || WeaponSelect == "Sword")
	{
		SwordUse--;
		cout << "Sword was used" << endl;
	}
	return SwordUse;
}

void Player::ZeroWeaponUse(int SwordUse, int BowUse)
{
	

	string ZeroUses = "This Weapon Has no more Uses. please select a differnt weapon.";
	if (SwordUse <= 0)
	{
		cout << ZeroUses << endl;
		
	}

	if (BowUse <= 0)
	{
		cout << ZeroUses << endl;
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