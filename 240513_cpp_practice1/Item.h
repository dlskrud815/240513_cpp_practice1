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
	float recoveryChance = 0; //포션 회복 확률
	int count = 0;
};

class Item
{
public:
	// 초기 생성자 실행 시 아이템 벡터 생성 후 데이터 넣기
	Item()
	{
		string line;
		ifstream itemData("ItemData.txt");

		this->itemType_num = 0;
		while (getline(itemData, line))
		{
			this->itemType_num++;
		}

		itemData.clear(); // 스트림의 상태 초기화
		itemData.seekg(0); // 파일 포인터를 파일의 시작으로 이동
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
