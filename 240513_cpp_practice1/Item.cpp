#include "Item.h"
#include "Function.h"

void Item::setCurrentItem()
{
	int type = Random(getItemType_num()) - 1;

	this->currentItem.name = this->itemInfo[type].name;
	this->currentItem.recoveryChance = this->itemInfo[type].recoveryChance;
}