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
	float recoveryChance; //���� ȸ�� Ȯ��
};

class Item
{
public:
	// �ʱ� ������ ���� �� ������ ���� ���� �� ������ �ֱ�
	Item()
	{
		// ������~~~~~
		ifstream itemData("ItemData.txt");

		itemType_num = 0;
		while (getline(itemData, line))
		{
			stringstream ss(line);
			ss >> itemInfo[itemType_num].name >> itemInfo[itemType_num].recoveryChance;
			itemType_num++;
		}

		monsterData.clear(); // ��Ʈ���� ���� �ʱ�ȭ
		monsterData.seekg(0); // ���� �����͸� ������ �������� �̵�
		this->monsterInfo.resize(monsterType_num);

		while (getline(itemData, line))
		{
			stringstream ss(line);
			ss >> itemInfo[itemType_num].name >> itemInfo[itemType_num].recoveryChance;
			itemType_num++;
		}

		itemData.close();
	}


private:
	int itemType_num;
	vector <ItemInfo> itemInfo;

	string line;
};
