#pragma once

#include "ItemStash.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct CharacterInfo
{
	string name;
	int level = 0;
	int item_num = 0;
	int dealDamage = 50;
	int exp = 0;
	int hp = 200;
};

class Character
{
public:
	Character(string name)
	{
		this->characterInfo.name = name;
	}

	CharacterInfo getCharacterInfo() { return this->characterInfo; }
	
	void setCharacterName(string name) { this->characterInfo.name = name; }
	void setCharacterItem_num(int total) { this->characterInfo.item_num = total; }
	void setCharacterExpUp() { this->characterInfo.exp = this->characterInfo.exp + 50; }
	void resetCharacterExpUp() { this->characterInfo.exp = 0; }
	void setCharacterLevelUp() { this->characterInfo.level = this->characterInfo.level + 1; }

	int getCharacterLevel() { return this->characterInfo.level; }
	int getCharacterExp() { return this->characterInfo.exp; }

	bool canGiveUp();
	int fightMonster(ItemStash item);

private:
	CharacterInfo characterInfo;

	int option;
};
