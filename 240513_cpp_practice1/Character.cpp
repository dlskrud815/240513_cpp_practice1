#include "Character.h"
#include "Monster.h"
//#include "ItemStash.h"
#include "Function.h"

int selectItem(ItemStash item);

bool Character::canGiveUp()
{
	if (Random(3) > 1) //2,3이면
	{
		return false; //도망실패
	}
	else //1이면
	{
		return true; //도망성공
	}
}

int Character::fightMonster(ItemStash item)
{
	int choice, damage;
	int type = Random(2);

	if (type == 1) //1: 선공
	{
		cout << endl << "플레이어: 내가 먼저다!" << endl;
	}
	else //2: 후공
	{
		cout << endl << "플레이어: 네가 먼저다!" << endl;
	}

	Sleep(500);

	cout << endl << "몬스터: 그 전에 게임 하나 해보지 않겠나?" << endl << "\t만약 이긴다면 두배 공격을 허락해주지." << endl << endl << "1)홀 2)짝" << endl
		<< "- 선택: ";
	cin >> choice;

	if (CheckEvenOdd(choice)) //맞힘
	{
		damage = 2;
		cout << endl << "쳇 정답이군." << endl;
	}
	else //틀림
	{
		damage = 1;
		cout << endl << "훗 틀렸다." << endl;
	}
	
	ifstream fightInfo("FightInfo.txt");
	string line, content;
	vector <string> v_fightInfo;

	while (getline(fightInfo, line))
	{
		stringstream ss(line);
		//cout << "확인: ";

		while (ss >> content)
		{
			v_fightInfo.push_back(content);
		}
	}

	fightInfo.close();

	Sleep(500); //0.5초

	while (1)
	{
		int my_item_num = stoi(v_fightInfo[7]);

		int my_hp = stoi(v_fightInfo[9]);
		int monster_hp = stoi(v_fightInfo[1]);

		int my_damage = stoi(v_fightInfo[8]);
		int monster_damage = stoi(v_fightInfo[3]);

		//몬스터 hp가 다 닳거나 내 hp가 다 닳음
		if (my_hp <= 0 || monster_hp <= 0)
		{
			cout << endl << "[전투 종료]" << endl;

			if (my_hp < 0)
			{
				return 1;
			}
			else
			{
				return 2;
			}
			
			//break; //전투 종료
		}

		switch (type)
		{
		case 1: //나 먼저
			cout << endl << "플레이어: 받아랏!" << endl;
			Sleep(500);

			switch (damage)
			{
			case 1: //평타
				my_damage = my_damage * 1;
				break;
			case 2: //데미지 두 배
				my_damage = my_damage * 2;
				break;
			}

			v_fightInfo[1] = to_string(monster_hp - my_damage);

			cout << endl << "- 플레이어 턴: " << v_fightInfo[0] << "(몬스터)이 데미지" << my_damage << "의 공격을 받았다." << endl;

			if (stoi(v_fightInfo[1]) <= 0)
			{
				cout << "몬스터 잔여 HP: 0" << endl;
			}
			else
			{
				cout << "몬스터 잔여 HP: " << v_fightInfo[1] << endl;
			}
			Sleep(500);

			type++;
			break;
		case 2: //몬스터 먼저
			cout << endl << "몬스터: 후후.." << endl;
			Sleep(500);

			v_fightInfo[9] = to_string(my_hp - monster_damage);
			

			cout << endl << "- 몬스터 턴: " << v_fightInfo[5] << "(플레이어)는 데미지" << monster_damage << "의 공격을 받았다." << endl;
			if (stoi(v_fightInfo[9]) <= 0)
			{
				cout << "플레이어 잔여 HP: 0" << endl;
			}
			else
			{
				cout << "플레이어 잔여 HP: " << v_fightInfo[9] << endl;
			}

			Sleep(500); //0.5초

			//아이템 사용 구현 필요
			if (my_item_num > 0)
			{
				cout << endl << "아이템을 사용하시겠습니까? " << endl
					<< "1) yes 2) no" << endl << "- 선택: ";
				cin >> option;

				int recovery = 0;

				switch (option)
				{
				case 1:
					//cout << "아이템 창" << endl;
					//HP 회복

					recovery = selectItem(item);
					v_fightInfo[9] = to_string(stoi(v_fightInfo[9]) + recovery);
					v_fightInfo[7] = to_string(stoi(v_fightInfo[7]) - 1);

					cout << endl << "** 플레이어 HP +" << recovery << " **" << endl << "----------------------" << endl;
					Sleep(500);
					break;
				case 2:
					break;
				}
			}

			type--;
			break;
		}

		//파일에 정보 다시 저장
		ofstream fightInfo("FightInfo.txt");

		fightInfo << v_fightInfo[0] << " "
			<< v_fightInfo[1] << " "
			<< v_fightInfo[2] << " "
			<< v_fightInfo[3] << " "
			<< v_fightInfo[4] << endl
			<< v_fightInfo[5] << " "
			<< v_fightInfo[6] << " "
			<< v_fightInfo[7] << " "
			<< v_fightInfo[8] << " "
			<< v_fightInfo[9] << " "
			<< v_fightInfo[10] << endl;

		fightInfo.close();

		//Sleep(500); //1.5초
	}
}

int selectItem(ItemStash item)
{
	//아이템
	int option, result = 0;
	string line;
	vector <ItemInfo> v_item;

	ifstream itemStatus("ItemStatus.txt");
	
	int i = 0;
	while (getline(itemStatus, line))
	{
		i++;
	}
	v_item.resize(i);
	
	itemStatus.clear(); // 스트림의 상태 초기화
	itemStatus.seekg(0); // 파일 포인터를 파일의 시작으로 이동

	i = 0;
	while (getline(itemStatus, line))
	{
		stringstream ss(line);
		ss >> v_item[i].name >> v_item[i].recoveryChance >> v_item[i].count;
		//cout << endl << v_item[i].name << v_item[i].recoveryChance << v_item[i].count << endl;
		i++;
	}

	itemStatus.close();

	cout << endl << "----- 아이템 현황 -----" << endl;
	i = 0;
	for (ItemInfo item : v_item)
	{
		cout << endl << i + 1 << ". " << item.name << endl
			<< "- 효능: HP +" << item.recoveryChance * 100 << endl
			<< "- 개수: " << item.count << "개" << endl;
		i++;
	}
	cout << endl << "----------------------" << endl;

	cout << endl << "사용할 아이템 번호를 입력해주세요" << endl << "- 선택: ";
	cin >> option;

	item.useItem(option - 1);

	cout << endl << "----------------------" << endl << v_item[option - 1].name << "을 사용했습니다." << endl;

	result = v_item[option - 1].recoveryChance * 100;

	return result;
}

/*
int Character::ManipulateCharacter(int option)
{
	string name;

	switch (option)
	{
	case 1:
		cout << "- 변경할 이름 입력: ";
		cin >> name;
		setName(name);
		cout << "이름이 변경되었습니다." << endl;
		break;
	case 2:
		cout << "Level Up! ";
		setLevelUp(getLevel());
		cout << "lv." << getLevel() << endl;
		break;
	case 3:
		cout << "아이템을 얻었습니다." << endl;
		setGetItem(getItem_num());
		break;
	case 4:
		if (getItem_num() > 0)
		{
			cout << "아이템을 사용했습니다." << endl;
			setUseItem(getItem_num()); //어떤 아이템 버릴 지 확인 필요!!
		}
		else
		{
			cout << "경고: 사용할 아이템이 없습니다." << endl;
		}
		break;
	case 5:
		cout << endl << "------------------" << endl
			<< "이름: " << getName() << endl
			<< "레벨: " << getLevel() << endl
			<< "아이템 수: " << getItem_num() << endl
			<< "------------------" << endl;
		break;
	}
	return option;
}
*/
