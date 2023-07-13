#include<iostream>
#include"SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int HP)
{
	Monster* IsMonster = new Monster;

	// ���ڿ��� ����
	// ( ������ ����ü�� �ִ� name�̶�� �迭�� NAME_LENGTH��� ���, �Ű����� name�� ���� �� )
	strcpy_s(IsMonster->name, NAME_LENGTH, name);

	// ����ü Monster�� �ִ� HP�� �Ű����� HP�� ���� ������.
	IsMonster->HP = HP;

	// ���� ó���� pTail�� nullptr�� �ʱ�ȭ���� �����̹Ƿ� 
	// pTail�� ���� ����ü���� �������ٲ���, ���� pTail�� nullptr�̸� pHead�� ����ü�� ��������.( ó�� �ѹ��� �۵��ϰ� ��. )
	if (list.pTail == nullptr)
	{
		list.pHead = IsMonster;
	}
	else
	{
		list.pTail->pNext = IsMonster;
	}

	// MonsterList�� �ִ� pTail�� ����ü�� ��������.
	// ���⼭ pTail�� ����ü�� ���� ��.
	list.pTail = IsMonster;
	return IsMonster;
}

int GetMonsterCount(const MonsterList& list)
{
	// ����ü�� pHead�� �����ϰ�
	Monster* IsMonster = list.pHead;
	int count{};

	// pHead�� nullptr�� �� ������ �ݺ��ؼ� count������ ���� �����ش�.
	// ���ÿ� pHead�� ����ؼ� ����� ���ҵ�� �̵������ش�.( ������ ��(nullptr)�� ���� �״� )
	// Travers( ��ȸ )�� ����
	while (IsMonster)
	{
		count++;
		IsMonster = IsMonster->pNext;
	}
	return count;
}

void PrintMonsters(const MonsterList& list)
{
	Monster* IsMonster = list.pHead;
	while (IsMonster)
	{
		std::cout << IsMonster->name << "," << IsMonster->HP << std::endl;
		IsMonster = IsMonster->pNext;
	}
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	Monster* IsMonster = list.pHead;
	while(IsMonster)
	{
		if (strcmp(IsMonster->name, name) == 0)
		{
			return IsMonster;
		}
		IsMonster = IsMonster->pNext;
	}
	return nullptr;
}

void DeleteAll(MonsterList& list)
{
	Monster* IsMonster = list.pHead;

	// �����
	Monster* pNext{};
	
	// pHead�� nullptr�� �ƴϸ�
	// �ݺ��ϸ� ���� �ش�.
	while (IsMonster)
	{
		pNext = IsMonster->pNext;
		delete IsMonster;
		IsMonster = pNext;
	}

	// �� �� �ٽ� �ʱ�ȭ
	list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
	Monster* IsMonster = list.pHead;
	Monster* Previous = nullptr;
	
	while (IsMonster)
	{
		if (strcmp(IsMonster->name, name) == 0)
		{
			break;
		}

		Previous = IsMonster;
		IsMonster = IsMonster->pNext;
	}

	if (!IsMonster)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	else if (Previous == nullptr)
	{
		list.pHead = IsMonster->pNext;
	}
	else if (IsMonster == list.pTail)
	{
		list.pTail = Previous;
		Previous->pNext = nullptr;
	}
	else
	{
		Previous->pNext = IsMonster->pNext;
	}
	return true;
}
