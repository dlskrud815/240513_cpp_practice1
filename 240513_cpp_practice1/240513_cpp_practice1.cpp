#include <iostream>
#include <fstream>

#include "Character.h"
#include "Monster.h"
#include "ItemStash.h"
#include "Function.h"

using namespace std;

int main()
{
	int option, random;
	ItemStash item;
	Monster monster;
	Character character("기본");
	ItemInfo itemStatusInfo;
	string name;

	cout << "** 몬헌 **" << endl;
	

	while (1)
	{
		cout << endl << "1)메뉴 2)여정 0)종료" << endl << "- 선택: ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			cout << endl << "1)닉변 2)상태창" << endl << "- 선택: ";
			cin >> option;

			switch (option)
			{
			case 1:
				cout << endl << "변경할 이름을 입력하세요" << endl << "이름: ";
				cin >> name;
				character.setCharacterName(name);

				cout << endl << "** " << name << "(으)로 이름이 변경되었습니다" << endl;
				break;
			case 2:
				cout << endl << "\"나와라 상태창!!!\"" << endl;
				Sleep(500);

				cout << endl << "----- 상태창 -----" << endl;
				cout << endl << "이름: " << character.getCharacterInfo().name << endl
					<< "레벨: " << character.getCharacterInfo().level << endl
					<< "아이템 수: " << character.getCharacterInfo().item_num << endl
					<< "HP: " << character.getCharacterInfo().hp << endl
					<< "딜량: " << character.getCharacterInfo().dealDamage << endl
					<< "경험치: " << character.getCharacterInfo().exp << endl;

				cout << endl << "-----------------" << endl;
				break;
			}
			break;
		case 2:
			random = Random(10);

			if (random > 7) //30% -> 이게 맞나? 랜덤 분포 손 봐야 할 듯
			{
				//아이템 드롭
				Sleep(500);
				item.setCurrentItem();
				cout << endl << "New!" << item.getCurrentItemName() << "(아이템)을 얻었습니다" << endl;
				item.setInventoryStatus();
				

				vector <ItemInfo> itemStatusInfo = item.getInventoryStatus();
				string line = "";

				for (int i = 0; i < itemStatusInfo.size(); i++)
				{
					line += itemStatusInfo[i].name + " " + to_string(itemStatusInfo[i].recoveryChance) + " " + to_string(itemStatusInfo[i].count) + "\n";
				}

				ofstream itemStatus("ItemStatus.txt");

				itemStatus << line;

				itemStatus.close();

				int item_num = item.getTotalItem_num();
				character.setCharacterItem_num(item_num);

				//인벤 확인
				int i = 0;
				cout << endl << "----- 인벤토리 -----" << endl;
				for (ItemInfo item : item.getInventoryStatus())
				{
					if (item.count > 0)
					{
						cout << endl << i + 1 << "." << item.name << " " << item.count << "개" << endl
							<< "- 효능: HP +" << item.recoveryChance * 100 << endl;
						i++;
					}
				}
				cout << endl << "-------------------" << endl;
			}
			else //70%
			{
				//몬스터 마주치기
				
				monster.setCurrentMonster();
				cout << endl << "!!! " << monster.getCurrentMonsterName() << "(몬스터)와 마주쳤습니다" << endl;
				cout << endl << "1)싸운다 2)도망친다" << endl << "- 선택: ";
				cin >> option;
				
				bool breakCheck = false;

				MonsterInfo fightMonsterInfo;
				CharacterInfo fightCharacterInfo;

				while (1)
				{
					if (breakCheck) break;

					ofstream fightInfo("FightInfo.txt");

					fightMonsterInfo = monster.getCurrentMonster();
					fightCharacterInfo = character.getCharacterInfo();

					fightInfo << fightMonsterInfo.name << " "
						<< fightMonsterInfo.hp << " "
						<< fightMonsterInfo.level << " "
						<< fightMonsterInfo.dealDamage << " "
						<< fightMonsterInfo.itemDropChance << endl
						<< fightCharacterInfo.name << " "
						<< fightCharacterInfo.level << " "
						<< fightCharacterInfo.item_num << " "
						<< fightCharacterInfo.dealDamage << " "
						<< fightCharacterInfo.hp << " "
						<< fightCharacterInfo.exp << endl;
					
					fightInfo.close();

					switch (option)
					{
					case 1:
						//몬스터와 싸운다
						cout << endl << "[전투]" << endl;

						if (character.fightMonster(item) == 1)
						{
							cout << "- 몬스터 승 -" << endl << endl
								<< "\"하하! 애송이 녀석.\"" << endl;
							cout << endl << "--------------------" << endl;
						}
						else
						{
								cout << "- 플레이어 승 -" << endl << endl
								<< "\"당연한 결과다.\"" << endl;
								cout << endl << "--------------------" << endl;
						}

						character.setCharacterExpUp(); //전투 한번 당 경험치 50 상승
						//cout << "확인용: 현재 경험치: " << character.getCharacterExp() << endl;

						breakCheck = true;
						break;
					case 2:
						if (character.canGiveUp())
						{
							cout << endl << "몬스터로 부터 도망치는데 성공했습니다!" << endl;
							breakCheck = true;
							break; //도망성공
						}
						else
						{
							cout << endl << "몬스터로 부터 도망치는데 실패했습니다" << endl;
							option = 1; //도망실패
						}

						Sleep(500);
					}

					if (character.getCharacterExp() == 100) //경험치 100마다
					{
						//레벨업
						character.setCharacterLevelUp();

						cout << endl << "----- 레벨 업 -----" << endl << endl
							<< "- 현재 레벨: " << character.getCharacterLevel() << endl;
						cout << endl << "------------------" << endl;

						//레벨업 후 경험치 초기화
						character.resetCharacterExpUp();
					}
				}
			}
			break;
		case 0:
			return 0;
		}
	}
}