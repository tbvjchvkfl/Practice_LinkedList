#include<iostream>
#include"DoubleLinkedList.h"

DMonster* CreateMonster(DMonsterList& Dlist, const char* name, const int HP)
{
	DMonster* DIsMonster = new DMonster;
	
	strcpy_s(DIsMonster->name, NAME_LENGTH, name);

	DIsMonster->HP = HP;


	
	if (Dlist.pTail == nullptr)
	{
		Dlist.pHead = DIsMonster;
	}
	
	else
	{
		Dlist.pHead->pPrevious = DIsMonster;
		Dlist.pTail->pNext = DIsMonster;
	}

	Dlist.pTail = DIsMonster;
	return DIsMonster;
}

int GetMonsterCount(const DMonsterList& Dlist)
{
	DMonster* DIsMonster = Dlist.pHead;
	int count{};
	
	while (DIsMonster != nullptr)
	{
		count++;
		DIsMonster = DIsMonster->pNext;
	}
	return count;
}

void PrintMonsters(const DMonsterList& Dlist)
{
	DMonster* DIsMonster = Dlist.pHead;
	while (DIsMonster)
	{
		std::cout << DIsMonster->name << DIsMonster->HP << std::endl;
		DIsMonster = DIsMonster->pNext;
	}
}

DMonster* FindMonsters(const DMonsterList& Dlist, const char* name)
{
	DMonster* DIsMonster = Dlist.pHead;
	while (DIsMonster)
	{
		if (strcmp(DIsMonster->name, name) == 0)
		{
			return DIsMonster;
		}
		DIsMonster = DIsMonster->pNext;
	}
	return nullptr;
}

void DeleteAll(DMonsterList& Dlist)
{
	DMonster* DIsMonster = Dlist.pHead;
	DMonster* pNext{};

	while (DIsMonster)
	{
		pNext = DIsMonster->pNext;
		delete DIsMonster;
		DIsMonster = pNext;
	}

	Dlist.pHead = Dlist.pTail = nullptr;
}

bool DeleteMonster(DMonsterList& list, const char* name)
{
	

	return false;
}
