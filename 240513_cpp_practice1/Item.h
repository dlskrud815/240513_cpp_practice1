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
	float recoveryChance; //포션 회복 확률
};

class Item
{
public:
	// 초기 생성자 실행 시 아이템 벡터 생성 후 데이터 넣기
	Item()
	{
		// 수정중~~~~~
		ifstream itemData("ItemData.txt");

		itemType_num = 0;
		while (getline(itemData, line))
		{
			stringstream ss(line);
			ss >> itemInfo[itemType_num].name >> itemInfo[itemType_num].recoveryChance;
			itemType_num++;
		}

		monsterData.clear(); // 스트림의 상태 초기화
		monsterData.seekg(0); // 파일 포인터를 파일의 시작으로 이동
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
