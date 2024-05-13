#include <iostream>

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

	cout << "** 몬헌 **" << endl;

	while (1)
	{
		cout << endl << "1)메뉴 2)여정 0)종료" << endl << "- 선택: ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			cout << "구현 중" << endl;
			break;
		case 2:
			random = Random(10);

			if (random > 7) //30% -> 이게 맞나? 랜덤 분포 손 봐야 할 듯
			{
				//아이템 드롭
				
				item.setCurrentItem();
				cout << endl << "New!" << item.getCurrentItemName() << "(아이템)을 얻었습니다" << endl;
				item.setInventoryStatus();
				
				//인벤 확인
				int i = 0;
				cout << endl << "현재 인벤토리 현황)" << endl << endl;
				for (ItemInfo item : item.getInventoryStatus())
				{
					if (item.count > 0)
					{
						cout << i + 1 << "." << item.name << " " << item.count << "개" << endl
							<< "- 효능: HP +" << item.recoveryChance * 100 << endl << endl;
						i++;
					}
				}
			}
			else //70%
			{
				//몬스터 마주치기
				
				monster.setCurrentMonster();
				cout << endl << "!!! " << monster.getCurrentMonsterName() << "(몬스터)와 마주쳤습니다" << endl;
				cout << endl << "1)싸운다 2)도망친다" << endl << "- 선택: ";
				cin >> option;
				
				bool breakCheck = false;
				while (1)
				{
					if (breakCheck) break;

					switch (option)
					{
					case 1:
						//몬스터와 싸운다
						cout << endl << "[전투]" << endl;
						character.fightMonster();
						breakCheck = true;
						break;
					case 2:
						if (character.canGiveUp())
						{
							cout << "몬스터로 부터 도망치는데 성공했습니다!" << endl;
							breakCheck = true;
							break; //도망성공
						}
						else
						{
							cout << "몬스터로 부터 도망치는데 실패했습니다" << endl;
							option = 1; //도망실패
						}
					}
				}
			}
			break;
		case 0:
			return 0;
		}
	}
}