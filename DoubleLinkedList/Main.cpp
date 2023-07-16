#include<iostream>
#include "DoubleLinkedList.h"


int main()
{
	DMonsterList myList;

	CreateMonster(myList, "´Á´ë", 20);
	CreateMonster(myList, "°õ", 40);
	CreateMonster(myList, "°Å¹Ì", 60);
	CreateMonster(myList, "¾Ç¸¶", 80);
	CreateMonster(myList, "¿ë", 100);
	PrintMonsters(myList);

	FindMonsters(myList, "¿ë");
	DeleteAll(myList);
}