#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct ItemInfo
{
	string name;
	float recoveryChance = 0; //���� ȸ�� Ȯ��
	int count = 0;
};

class Item
{
public:
	// �ʱ� ������ ���� �� ������ ���� ���� �� ������ �ֱ�
	Item()
	{
		string line;
		ifstream itemData("ItemData.txt");

		this->itemType_num = 0;
		while (getline(itemData, line))
		{
			this->itemType_num++;
		}

		itemData.clear(); // ��Ʈ���� ���� �ʱ�ȭ
		itemData.seekg(0); // ���� �����͸� ������ �������� �̵�
		this->itemInfo.resize(itemType_num);

		this->itemType_num = 0;
		while (getline(itemData, line))
		{
			stringstream ss(line);
			ss >> this->itemInfo[this->itemType_num].name >> this->itemInfo[this->itemType_num].recoveryChance;
			this->itemType_num++;
		}

		itemData.close();
	}

	int getItemType_num() { return this->itemType_num; }
	string getCurrentItemName() { return this->currentItem.name; }
	ItemInfo getCurrentItem() { return this->currentItem; }

	vector <ItemInfo> getInventoryStatus() { return this->itemInfo; }
	
	void setInventoryStatus();
	void setCurrentItem();

private:
	int itemType_num;
	vector <ItemInfo> itemInfo;

	ItemInfo currentItem;
};
