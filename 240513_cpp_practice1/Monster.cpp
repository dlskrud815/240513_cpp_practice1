#include "Monster.h"
#include "Function.h"

void Monster::setCurrentMonster()
{
	int type = Random(getMonsterType_num()) - 1;

	this->currentMonster.name = this->monsterInfo[type].name;
	this->currentMonster.hp = this->monsterInfo[type].hp;
	this->currentMonster.level = this->monsterInfo[type].level;
	this->currentMonster.dealDamage = this->monsterInfo[type].dealDamage;
	this->currentMonster.itemDropChance = this->monsterInfo[type].itemDropChance;
}