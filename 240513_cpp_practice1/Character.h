#pragma once
#include <iostream>

using namespace std;

class Character
{
public:
	Character(string name)
	{
		this->name = name;
		this->level = 0;
		this->item_num = 0;
		this->exp = 0;
		this->hp = 0;
	}

	int ManipulateCharacter(int option);

	string getName() { return this->name; }
	int getLevel() { return this->level; }
	int getItem_num() { return this->item_num; }
	int getExp() { return this->exp; }
	int getHp() { return this->hp; }

	void setName(string name) { this->name = name; }
	void setLevelUp(int level) { this->level = level + 1; }
	void setGetItem(int item_num) { this->item_num = item_num + 1; }
	void setUseItem(int item_num) { this->item_num = item_num - 1; }

	void attackMonster();

private:
	string name;
	int level;
	int item_num;

	int hp;
	int exp;

	int option;
};
