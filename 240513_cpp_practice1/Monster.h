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
	float itemDropChance=0; //����ų ������ ��� Ȯ��
};

class Monster
{
public:
	// �ʱ� ������ ���� �� ���� ���� ���� �� ������ �ֱ�
	Monster()
	{
		string line;
		ifstream monsterData("MonsterData.txt");

		this->monsterType_num = 0;
		while (getline(monsterData, line))
		{
			this->monsterType_num++;
		}

		monsterData.clear(); // ��Ʈ���� ���� �ʱ�ȭ
		monsterData.seekg(0); // ���� �����͸� ������ �������� �̵�
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
