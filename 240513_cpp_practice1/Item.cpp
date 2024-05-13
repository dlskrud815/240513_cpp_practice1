#include "Item.h"
#include "Function.h"

void Item::setCurrentItem()
{
	int type = Random(getItemType_num()) - 1;

	this->currentItem.name = this->itemInfo[type].name;
	this->currentItem.recoveryChance = this->itemInfo[type].recoveryChance;
}

void Item::setInventoryStatus()
{
	int i = 0;
	for (ItemInfo item : this->itemInfo)
	{
		if (Item::getCurrentItem().name == item.name)
		{
			this->itemInfo[i].count = this->itemInfo[i].count + 1;
		}
		i++;
	}
}