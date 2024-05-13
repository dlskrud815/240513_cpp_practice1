#include <iostream>

//#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "Function.h"

using namespace std;

int main()
{
	int option, random;
	Item item;
	Monster monster;
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

			if (random > 7) //30%
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
			}
			break;
		case 0:
			return 0;
		}
	}
}