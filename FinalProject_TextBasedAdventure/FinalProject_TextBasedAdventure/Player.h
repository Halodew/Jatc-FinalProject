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
	int Health = 100;
	
	
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
