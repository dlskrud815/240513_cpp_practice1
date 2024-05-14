#include "ItemStash.h"
#include "Function.h"

void ItemStash::setCurrentItem()
{
	int type = Random(getItemType_num()) - 1;

	this->currentItem.name = this->itemInfo[type].name;
	this->currentItem.recoveryChance = this->itemInfo[type].recoveryChance;
}

void ItemStash::setInventoryStatus()
{
	int i = 0;
	for (ItemInfo item : this->itemInfo)
	{
		if (ItemStash::getCurrentItem().name == item.name)
		{
			this->itemInfo[i].count = this->itemInfo[i].count + 1;
		}
		i++;
	}
}

int ItemStash::getTotalItem_num()
{
	int total = 0;

	for (ItemInfo item : this->itemInfo)
	{
		total = total + item.count;
	}

	return total;
}