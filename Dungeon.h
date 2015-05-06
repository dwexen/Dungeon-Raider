/*
*Matthew Colozzo
*"I pledge my honor that I have abided by the Stevens Honor System."
*/
#ifndef _DUNGEON_
#define _DUNGEON_

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

typedef unsigned int uint;

class Dungeon
{
 private:
  
	uint n;
	uint **adj;
	bool *visited;
	uint **resNet;
	
	void makeMatrix(uint n);
	void display();
	void dfs(uint s);
	void bfs(uint s);
	void unvisitAll();
	uint nextNeighbor(uint v, uint w);
	void swap(int*& arr, int x, int y);
	int ratioCalc(int roomInd);
	int* myDijkstra(uint s);
	uint myPizza(uint start, uint target, uint budget);

  
  
  class Room{
	public:
	string name;
	string monster;
	unsigned int strength;
	unsigned int treasure;
	Room()
	{
		name = "empty";
		monster = "empty";
		strength = -1;
		treasure = 0;
	}
	Room(string n, string m, uint s, uint t)
	{
		name =  n;
		monster = m;
		strength = s;
		treasure = t;
	}
  };
  class Hero{
	public:
	string name;
	unsigned int strength;
	unsigned int HP;
	static unsigned int cash;
	Hero()
	{
		name = "empty";
		strength = -1;
		HP = 0;
	}
	Hero(string n, uint s, uint hp)
	{
		name = n;
		strength = s;
		HP = hp;
	}
	};
	//Room rooms[];
	//Hero heroes[];
	Room* rooms;
	uint roomsLength;
	uint roomCap;
	
	Hero* heroes;
	uint heroesLength;
	uint heroCap;
	
public:
/*
*Constructor that sets all variable basic values
*/
 Dungeon() { 
	rooms = new Room[5]; 
	heroes = new Hero[5]; 
	roomsLength = 5; 
	heroesLength = 5; 
	makeMatrix(5);
	roomCap = 0;
	heroCap = 0;
};
/*
*Pre-condition: two unsigned integers
*
*Post-condition: Added the node to the tree properly
*
*@param: 		r - the maximum number of rooms, h the maximum number of heroes
*/
 Dungeon(unsigned int r, unsigned int h) { 
	if( r < 5 )
	{
		rooms = new Room[5];
		roomsLength = 5;
	}
	else	
		rooms = new Room[r];
		roomsLength = r;
	if( h < 5 )
	{
		heroes = new Hero[5];
		heroesLength = 5;
	}
	else
		heroes = new Hero[h];
		heroesLength = h;
	makeMatrix(r);
	roomCap = 0;
	heroCap = 0;
 };
 /*
 *Destructor
 */
 ~Dungeon()
 {
	delete[] rooms;
	delete[] heroes;
	for(int i = 0; i < n; i++)
	{
		delete[] adj[i];
	}
	delete[] adj;
	delete[] visited;
 }
 
 // adds a new room to the dungeon with the given name, monster, 
 //strength and dollars (in that order). Returns the index of the room in the dungeon 
 //or -1 if for some reason you decide not to add it (like lack of space left in the dungeon).
 int addRoom(string name, string monster, unsigned int strength, unsigned int dollars);
 
 // sets an edge between src and dst with weight cap. Returns true if all 
// good, false if the indexes given for src or dst are not valid. 
// Use a cap of 0 to remove an edge.
 bool setHall(unsigned int src, unsigned int dst, unsigned int cap);
 
 //adds a new hero to the pool of heroes. Start them up with no cash by default, 
 //but make sure that if you add a new hero after the previous ones already had some, 
 //they won't lose the money they had. Returns false if there is no more room for heroes
 bool addHero(string name, unsigned int strength, unsigned int hp);
 
//displays all rooms preceded by their index
 void listRooms();
 
 //BFS of the rooms and shows all the info regarding that room, one room per line, 
 //==== separator between disjoint rooms, Begins traversal at index 0
 void breadthRooms();
 
 //DFS of the rooms and shows all the info regarding that room, one room per line, 
 //==== separator between disjoint rooms, Begins traversal at index 0
 void depthRooms();
 
 //display either your adjacency matrix, or a list of all your edges. 
 //If you do the latter, show the edges as: srcIndex--weight-->dstIndex. e.g.
// 0--2-->3 would mean there is an edge of weight 2 from room 0 to 3
 void showHalls();
 
 //display the list of all heroes and their current status. Only print their cash stash once
 void showHeroes();
 
 void safestConnection();
 // display the Most Safe Pizza sharing halls. 
 //Prims but use the edges with max values instead of min. 
 //Prints used and their weights. Considers each "hall" as an 
 //undirected edge with weight equal to the sum of both directions for this algorithm.
 void mst();
 
 void lucrativePath(uint start);
 void lucrativePaths();
 uint pizzaParty(uint start, uint target, uint budget);
	
};





#endif
