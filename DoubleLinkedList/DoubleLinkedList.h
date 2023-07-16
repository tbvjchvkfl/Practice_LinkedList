#pragma once
#include"DMonster.h"

struct DMonsterList
{
	// �� �༮���� ��Ŀ����
	DMonster* pHead{};
	DMonster* pTail{};
};


DMonster* CreateMonster(DMonsterList& Dlist, const char* name, const int HP);
int GetMonsterCount(const DMonsterList& Dlist);
void PrintMonsters(const DMonsterList& Dlist);
DMonster* FindMonsters(const DMonsterList& Dlist, const char* name);
void DeleteAll(DMonsterList& Dlist);
bool DeleteMonster(DMonsterList& list, const char* name);