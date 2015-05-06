/**
*room.cpp
*
*"I pledge my honor that I have abided by the Stevens Honor System."
*
*Matthew Colozzo (c) 2015
*
*/
#include "Dungeon.h"

uint Dungeon::Hero::cash;

/*
*Pre-condition: Valid user input and the maximum number of rooms have not already been added
*
*Post-condition: Room added to graph
*
*@param: 		name - the name of the room, monster - the name of the monster in the room, 
*strength - the difficulty of the room, dollars - the amount of treasure in the room, 
*/
int Dungeon::addRoom(string name, string monster, uint strength, uint dollars)
{
	if(roomCap < roomsLength)
	{
		rooms[roomCap] = Room(name, monster, strength, dollars);
		roomCap++;
		return roomCap;
	}
	return -1;
}

/*
*Pre-condition: Valid user input and the maximum number of heroes have not already been added
*
*Post-condition: Room added to graph
*
*@param: 		name - the name of the hero, 
*strength - the strength of the hero, hp - the amount of health the hero has, 
*/
bool Dungeon::addHero(string name, unsigned int strength, unsigned int hp)
{
	if(heroCap < heroesLength)
	{
		heroes[heroCap] = Hero(name, strength, hp);
		heroCap++;
		return true;
	}
	return false;
}

/*
*Pre-condition: There exist rooms to list
*
*Post-condition: Room added to graph
*
*@param: 		name - the name of the room, monster - the name of the monster in the room, 
*strength - the difficulty of the room, dollars - the amount of treasure in the room, 
*/
void Dungeon::listRooms()
{
	for(int i = 0; i < roomCap; i++)
	{
		cout<< i << " " << rooms[i].name <<endl;
	}
}

/*
*Pre-condition: There exist heroes to show
*
*Post-condition: Each hero listed with all their info
*
*@param: 		none
*/
void Dungeon:: showHeroes()
{
	for(int i = 0; i < heroCap; i++)
	{
		cout<< heroes[i].name << ":" << "\n" << "Strength: " << heroes[i].strength << "\n" << "HP: " << heroes[i].HP <<endl;
	}
	cout<< "Total gold: " << Hero::cash <<endl;
}


