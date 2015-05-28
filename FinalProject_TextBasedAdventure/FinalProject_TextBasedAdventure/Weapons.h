#ifndef WEAPONS_H
#define WEAPONS_H

//used if desited to have weapons with diffent damage values.

#include <stdlib.h>
#include <time.h>
using namespace std;
class Weapons
{
public:
	int DamageMod();

private:
	int base = 1;
	int melee = 10;
	int range = 5;
	int Modifer;

};


int Weapons::DamageMod()
{
	const int MaxValue = 100;
	const int MinValue = 1;

	srand(time(NULL));
	int Modifer = rand() % MaxValue + MinValue;

	return Modifer;
}

#endif