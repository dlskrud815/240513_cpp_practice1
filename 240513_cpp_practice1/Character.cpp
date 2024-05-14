#include "Character.h"
#include "Monster.h"
//#include "ItemStash.h"
#include "Function.h"

int selectItem(ItemStash item);

bool Character::canGiveUp()
{
	if (Random(3) > 1) //2,3�̸�
	{
		return false; //��������
	}
	else //1�̸�
	{
		return true; //��������
	}
}

int Character::fightMonster(ItemStash item)
{
	int choice, damage;
	int type = Random(2);

	if (type == 1) //1: ����
	{
		cout << endl << "�÷��̾�: ���� ������!" << endl;
	}
	else //2: �İ�
	{
		cout << endl << "�÷��̾�: �װ� ������!" << endl;
	}

	Sleep(500);

	cout << endl << "����: �� ���� ���� �ϳ� �غ��� �ʰڳ�?" << endl << "\t���� �̱�ٸ� �ι� ������ ���������." << endl << endl << "1)Ȧ 2)¦" << endl
		<< "- ����: ";
	cin >> choice;

	if (CheckEvenOdd(choice)) //����
	{
		damage = 2;
		cout << endl << "�� �����̱�." << endl;
	}
	else //Ʋ��
	{
		damage = 1;
		cout << endl << "�� Ʋ�ȴ�." << endl;
	}
	
	ifstream fightInfo("FightInfo.txt");
	string line, content;
	vector <string> v_fightInfo;

	while (getline(fightInfo, line))
	{
		stringstream ss(line);
		//cout << "Ȯ��: ";

		while (ss >> content)
		{
			v_fightInfo.push_back(content);
		}
	}

	fightInfo.close();

	Sleep(500); //0.5��

	while (1)
	{
		int my_item_num = stoi(v_fightInfo[7]);

		int my_hp = stoi(v_fightInfo[9]);
		int monster_hp = stoi(v_fightInfo[1]);

		int my_damage = stoi(v_fightInfo[8]);
		int monster_damage = stoi(v_fightInfo[3]);

		//���� hp�� �� ��ų� �� hp�� �� ����
		if (my_hp <= 0 || monster_hp <= 0)
		{
			cout << endl << "[���� ����]" << endl;

			if (my_hp < 0)
			{
				return 1;
			}
			else
			{
				return 2;
			}
			
			//break; //���� ����
		}

		switch (type)
		{
		case 1: //�� ����
			cout << endl << "�÷��̾�: �޾ƶ�!" << endl;
			Sleep(500);

			switch (damage)
			{
			case 1: //��Ÿ
				my_damage = my_damage * 1;
				break;
			case 2: //������ �� ��
				my_damage = my_damage * 2;
				break;
			}

			v_fightInfo[1] = to_string(monster_hp - my_damage);

			cout << endl << "- �÷��̾� ��: " << v_fightInfo[0] << "(����)�� ������" << my_damage << "�� ������ �޾Ҵ�." << endl;

			if (stoi(v_fightInfo[1]) <= 0)
			{
				cout << "���� �ܿ� HP: 0" << endl;
			}
			else
			{
				cout << "���� �ܿ� HP: " << v_fightInfo[1] << endl;
			}
			Sleep(500);

			type++;
			break;
		case 2: //���� ����
			cout << endl << "����: ����.." << endl;
			Sleep(500);

			v_fightInfo[9] = to_string(my_hp - monster_damage);
			

			cout << endl << "- ���� ��: " << v_fightInfo[5] << "(�÷��̾�)�� ������" << monster_damage << "�� ������ �޾Ҵ�." << endl;
			if (stoi(v_fightInfo[9]) <= 0)
			{
				cout << "�÷��̾� �ܿ� HP: 0" << endl;
			}
			else
			{
				cout << "�÷��̾� �ܿ� HP: " << v_fightInfo[9] << endl;
			}

			Sleep(500); //0.5��

			//������ ��� ���� �ʿ�
			if (my_item_num > 0)
			{
				cout << endl << "�������� ����Ͻðڽ��ϱ�? " << endl
					<< "1) yes 2) no" << endl << "- ����: ";
				cin >> option;

				int recovery = 0;

				switch (option)
				{
				case 1:
					//cout << "������ â" << endl;
					//HP ȸ��

					recovery = selectItem(item);
					v_fightInfo[9] = to_string(stoi(v_fightInfo[9]) + recovery);
					v_fightInfo[7] = to_string(stoi(v_fightInfo[7]) - 1);

					cout << endl << "** �÷��̾� HP +" << recovery << " **" << endl << "----------------------" << endl;
					Sleep(500);
					break;
				case 2:
					break;
				}
			}

			type--;
			break;
		}

		//���Ͽ� ���� �ٽ� ����
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

		//Sleep(500); //1.5��
	}
}

int selectItem(ItemStash item)
{
	//������
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
	
	itemStatus.clear(); // ��Ʈ���� ���� �ʱ�ȭ
	itemStatus.seekg(0); // ���� �����͸� ������ �������� �̵�

	i = 0;
	while (getline(itemStatus, line))
	{
		stringstream ss(line);
		ss >> v_item[i].name >> v_item[i].recoveryChance >> v_item[i].count;
		//cout << endl << v_item[i].name << v_item[i].recoveryChance << v_item[i].count << endl;
		i++;
	}

	itemStatus.close();

	cout << endl << "----- ������ ��Ȳ -----" << endl;
	i = 0;
	for (ItemInfo item : v_item)
	{
		cout << endl << i + 1 << ". " << item.name << endl
			<< "- ȿ��: HP +" << item.recoveryChance * 100 << endl
			<< "- ����: " << item.count << "��" << endl;
		i++;
	}
	cout << endl << "----------------------" << endl;

	cout << endl << "����� ������ ��ȣ�� �Է����ּ���" << endl << "- ����: ";
	cin >> option;

	item.useItem(option - 1);

	cout << endl << "----------------------" << endl << v_item[option - 1].name << "�� ����߽��ϴ�." << endl;

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
		cout << "- ������ �̸� �Է�: ";
		cin >> name;
		setName(name);
		cout << "�̸��� ����Ǿ����ϴ�." << endl;
		break;
	case 2:
		cout << "Level Up! ";
		setLevelUp(getLevel());
		cout << "lv." << getLevel() << endl;
		break;
	case 3:
		cout << "�������� ������ϴ�." << endl;
		setGetItem(getItem_num());
		break;
	case 4:
		if (getItem_num() > 0)
		{
			cout << "�������� ����߽��ϴ�." << endl;
			setUseItem(getItem_num()); //� ������ ���� �� Ȯ�� �ʿ�!!
		}
		else
		{
			cout << "���: ����� �������� �����ϴ�." << endl;
		}
		break;
	case 5:
		cout << endl << "------------------" << endl
			<< "�̸�: " << getName() << endl
			<< "����: " << getLevel() << endl
			<< "������ ��: " << getItem_num() << endl
			<< "------------------" << endl;
		break;
	}
	return option;
}
*/
