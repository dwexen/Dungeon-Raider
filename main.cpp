/**
*main.cpp
*
*"I pledge my honor that I have abided by the Stevens Honor System."
*
*Matthew Colozzo (c) 2015
*
*/
#include "Dungeon.h"

void testBipartiteOddEven(uint n, uint m)
{
	Dungeon d((n+m), 5);
	for(uint i = 0; i < (n+m); i++)
	{
		d.addRoom("aaaaah", "matt", i, 100);
	}
	for(uint j = 0; j < n; j++){
		for(uint k = n; k < (n+m); k++)
		{
			uint weight = ((j+5)*31+(k+5)*37) % 233;
			if(weight % 2 == 0)
			{
				d.setHall(j,k,weight);
			}
			else{
				d.setHall(k, j, weight);
			}
		}
	}
	d.depthRooms();
	d.breadthRooms();
	d.mst();
}
int main()
{
	#if 0
	Dungeon d(7, 5);
	d.addRoom("room0","jeff", 4, 100);
	d.addRoom("room1","bill", 5, 110);
	d.addRoom("room2", "jill", 5, 110);
	d.addRoom("room3", "jake", 5, 110);
	d.addRoom("room4", "rex", 5, 110);
	d.addRoom("room5", "Ishouldntbehere", 5, 110);
	d.addRoom("room6", "eck", 5, 110);
	d.addHero("mike", 6, 50);
	d.setHall(0, 1,5);
	d.setHall(1,3,9);
	d.setHall(3,4,17);
	d.setHall(0, 2, 77);
	d.setHall(0, 6, 102);
	d.setHall(-1, 1, 5);
	d.setHall(3, 6, 40);
	d.setHall(6, 5, 50);
	d.setHall(5, 6, 50);
	d.setHall(4, 2, 60);
	d.setHall(4, 5, 60);
	
	d.depthRooms();
	//d.listRooms();
	//d.showHalls();
	//d.showHeroes();
	d.breadthRooms();
	d.mst();
	#endif
	
	#if 0
	Dungeon d(7, 5);
	d.addRoom("room0", "blah", 4, 420);
	d.addRoom("room1", "blah", 4, 420);
	d.addRoom("room2", "blah", 4, 420);
	d.addRoom("room3", "blah", 4, 420);
	d.addRoom("room4", "blah", 4, 420);
	d.addRoom("room5", "blah", 4, 420);
	d.addRoom("room6", "blah", 4, 420);
	
	d.setHall(0, 1, 5);
	d.setHall(0, 3, 12);
	d.setHall(0, 5, 3);
	d.setHall(1, 2, 9);
	d.setHall(1, 3, 57);
	d.setHall(2, 4, 6);
	d.setHall(3, 1, 73);
	d.setHall(3, 2, 42);
	d.setHall(3, 4, 19);
	d.setHall(4, 0, 1);
	d.setHall(5, 1, 21);
	d.setHall(5, 2, 7);
	d.setHall(4, 3,12);
	d.setHall(4, 5, 9);
	d.setHall(2, 0, 33);
	
	d.mst();
	//d.depthRooms();
	//d.breadthRooms();
	#endif
	#if 0
	Dungeon d(10, 5);
	d.addRoom("room0", "blah", 4, 420);
	d.addRoom("room1", "blah", 4, 420);
	d.addRoom("room2", "blah", 4, 420);
	d.addRoom("room3", "blah", 4, 420);
	d.addRoom("room4", "blah", 4, 420);
	d.addRoom("room5", "blah", 4, 420);
	d.addRoom("room6", "blah", 4, 420);
	d.addRoom("room7", "blah", 4, 420);
	d.addRoom("room8", "blah", 4, 420);
	d.addRoom("room9", "blah", 4, 420);
	
	for(uint i = 0; i < 10; i++)
	{
		for(uint j = 0; j < 10; j++)
		{
			d.setHall(i, j, ((i*10) + j));
		}
	}
	
	d.mst();
	d.depthRooms();
	d.breadthRooms();
	#endif
	#if 0
	Dungeon d(4, 5);
	
	d.addRoom("A", "blah", 5, 15);
	d.addRoom("B", "blah", 4, 9);
	d.addRoom("C", "blah", 7, 60);
	d.addRoom("D", "blah", 10, 10000);
	
	d.setHall(0, 1, 1);
	d.setHall(1, 0, 1);
	d.setHall(2, 0, 200);
	d.setHall(2, 1, 100);
	d.setHall(0, 3, 100);
	d.setHall(1, 3, 200);
	
	d.pizzaParty(2, 3, 50);
	
	#endif
	#if 1
	Dungeon dungeon(6,6);
	dungeon.addRoom("Room A","Monster 1",3,10);
	dungeon.addRoom("Room B","Monster 2",5,3);
	dungeon.addRoom("Room C","Monster 3",10,20);
	dungeon.addRoom("Room D","Monster 4",8,5);
	dungeon.addRoom("Room E","Monster 5",10,1);
	dungeon.addRoom("Room F","Monster 6",4,7);
	dungeon.setHall(0,3,4);
	dungeon.setHall(0,2,8);
	dungeon.setHall(1,4,7);
	dungeon.setHall(2,1,6);
	dungeon.setHall(2,5,7);
	dungeon.setHall(3,0,3);
	dungeon.setHall(3,1,4);
	dungeon.setHall(3,4,3);
	dungeon.setHall(4,3,6);
	dungeon.setHall(5,1,10);
	dungeon.setHall(5,4,8);
	
	dungeon.lucrativePath(0);
	dungeon.pizzaParty(0, 5, 6);
	#endif
	
	#if 0
	Dungeon d(5, 5);
	d.addRoom("A", "blah", 5, 15);
	d.addRoom("B", "blah", 4, 9);
	d.addRoom("C", "blah", 7, 60);
	d.addRoom("D", "blah", 10, 10000);
	d.addRoom("E", "blah", 9, 120);
	
	d.setHall(0, 1, 5);
	d.setHall(1, 0, 6);
	d.setHall(1, 2, 3);
	d.setHall(2, 3, 9);
	d.setHall(0, 3, 10);
	d.setHall(0, 4, 11);
	d.setHall(1, 3, 3);
	d.setHall(4, 3, 5);
	d.setHall(0, 2, 2);
	d.setHall(2, 1, 30);
	
	//d.mst();
	//d.depthRooms();
	//d.breadthRooms();
	
	//d.addHero("mike", 6, 50);
	//d.addHero("mike", 6, 50);
	//d.addHero("mike", 6, 50);
	//d.addHero("mike", 6, 50);
	
	//d.listRooms();
	//d.showHalls();
	//d.showHeroes();
	
	d.lucrativePath(2);
	d.lucrativePaths();
	d.pizzaParty(0, 3, 1250);
	#endif
	
	//testBipartiteOddEven(6,4);
	#if 0
	Dungeon d(15, 5);
	d.addRoom("room0", "blah", 4, 420);
	d.addRoom("room1", "blah", 4, 420);
	d.addRoom("room2", "blah", 4, 420);
	d.addRoom("room3", "blah", 4, 420);
	d.addRoom("room4", "blah", 4, 420);
	d.addRoom("room5", "blah", 4, 420);
	d.addRoom("room6", "blah", 4, 420);
	d.addRoom("room7", "blah", 4, 420);
	d.addRoom("room8", "blah", 4, 420);
	d.addRoom("room9", "blah", 4, 420);
	d.addRoom("room10", "blah", 4, 420);
	d.addRoom("room11", "blah", 4, 420);
	d.addRoom("room12", "blah", 4, 420);
	d.addRoom("room13", "hey", 4, 20);
	d.addRoom("room14", "yo", 4, 20);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	d.addHero("mike", 6, 50);
	
	d.showHeroes();
	
	d.setHall(13, 14, 6);
	d.setHall(4,1,12);
	d.setHall(1,2,37);
	d.setHall(2,3,100);
	d.setHall(3,4,420);
	d.setHall(4,3,9);
	d.setHall(1,5,70);
	d.setHall(1,6,40);
	d.setHall(2,7,7);
	d.setHall(2,8,18);
	d.setHall(3,9,14);
	d.setHall(3,10,10);
	d.setHall(4,11,700);
	d.setHall(4,12,1000);
	d.setHall(0, 0, 20);
	
	d.depthRooms();
	d.breadthRooms();
	d.mst();
	
	d.showHalls();
	#endif
	
	#if 0
	
	Dungeon d(15, 5);
	d.addRoom("room0", "blah", 4, 420);
	d.addRoom("room1", "blah", 4, 420);
	d.addRoom("room2", "blah", 4, 420);
	d.setHall(0, 1, 5);
	d.setHall(0, 2, 5);
	d.setHall(1, 0, 5);
	d.setHall(1, 2, 5);
	d.setHall(2, 0, 5);
	d.setHall(2, 1, 5);
	
	d.mst();
	#endif
	
	#if 0
	
	Dungeon d(5, 5);
	
	d.addRoom("A", "scarydude",5,7);
	d.addRoom("B", "scarierdude", 9, 8);
	d.addRoom("C", "scariestdude", 20, 24);
	d.addRoom("D", "dsafasdfasdf", 50, 100);
	
	d.setHall(0, 1, 5);
	d.setHall(1, 0, 5);
	d.setHall(1, 2, 5);
	d.setHall(2, 1, 5);
	d.setHall(0, 2, 5);
	d.setHall(2, 0, 5);
	d.setHall(2, 3, 5);
	
	d.lucrativePath(0);
	#endif
	
}



