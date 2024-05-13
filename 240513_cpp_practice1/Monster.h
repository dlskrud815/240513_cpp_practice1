#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct MonsterInfo
{
	string name;
	int hp=0;
	int level=0;
	int dealDamage=0;
	float itemDropChance=0; //몬스터킬 아이템 드롭 확률
};

class Monster
{
public:
	// 초기 생성자 실행 시 몬스터 벡터 생성 후 데이터 넣기
	Monster()
	{
		string line;
		ifstream monsterData("MonsterData.txt");

		this->monsterType_num = 0;
		while (getline(monsterData, line))
		{
			this->monsterType_num++;
		}

		monsterData.clear(); // 스트림의 상태 초기화
		monsterData.seekg(0); // 파일 포인터를 파일의 시작으로 이동
		this->monsterInfo.resize(monsterType_num);

		this->monsterType_num = 0;
		while (getline(monsterData, line))
		{
			stringstream ss(line);
			ss >> this->monsterInfo[this->monsterType_num].name >> this->monsterInfo[this->monsterType_num].hp
				>> this->monsterInfo[this->monsterType_num].level >> this->monsterInfo[this->monsterType_num].dealDamage
				>> this->monsterInfo[this->monsterType_num].itemDropChance;

			this->monsterType_num++;
		}

		monsterData.close();
	}

	int getMonsterType_num() { return this->monsterType_num; }
	string getCurrentMonsterName() { return this->currentMonster.name; }
	MonsterInfo getCurrentMonster() { return this->currentMonster; }
	
	void setCurrentMonster();

private:
	int monsterType_num;
	vector <MonsterInfo> monsterInfo;

	MonsterInfo currentMonster;
};
