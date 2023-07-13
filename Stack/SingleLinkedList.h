#pragma once
#include"Monster.h"

struct MonsterList
{
	Monster* pHead{};
	Monster* pTail{};
};

Monster* CreateMonster(MonsterList& list, const char* name, const int HP);
int GetMonsterCount(const MonsterList& list);
void PrintMonsters(const MonsterList& list);
Monster* FindMonster(const MonsterList& list, const char* name);
void DeleteAll(MonsterList& list);
bool DeleteMonster(MonsterList& list, const char* name);