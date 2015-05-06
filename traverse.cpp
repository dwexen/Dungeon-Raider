/**
*traverse.cpp
*
*"I pledge my honor that I have abided by the Stevens Honor System."
*
*Matthew Colozzo (c) 2015
*
*/
#include "Dungeon.h"

/*
*Pre-condition: A graph to traverse exists
*
*Post-condition: Printed order of a Depth-first search, disjoint nodes are marked
*
*@param: 		none
*/
void Dungeon::depthRooms()
{
	int v;
	unvisitAll();
	for(v = 0; v < roomCap; v++)
	{
		if(!visited[v])
		{
			dfs(v);
			cout<<"====" <<endl;
		}
	}
}

void Dungeon::dfs(uint s)
{
	uint v = 0;
	if(s < roomCap && !visited[s])
	{
		cout<< rooms[s].name << " monster: " << rooms[s].monster << " strength: " << rooms[s].strength << " loot: " << rooms[s].treasure <<endl;
		visited[s] = true;
		for(v = nextNeighbor(s, v); v < roomCap; v = nextNeighbor(s, v))
		{
			if(!visited[v])
			{
				dfs(v);
			}
		}
	}
}

/*
*Pre-condition: A graph to traverse exists
*
*Post-condition: Printed order of a Breadth-first search, disjoint nodes are marked
*
*@param: 		none
*/
void Dungeon::breadthRooms()
{
	int v; 
	unvisitAll();
	for(v = 0; v < roomCap; v++)
	{
		if(!visited[v])
		{
			bfs(v);
			cout<< "====" <<endl;
		}
	}
}

void Dungeon::bfs(uint s)
{
	uint *arr = new uint[roomCap];
	uint addIndex = 0;
	uint removeIndex = 0;
	uint v = 0;
	if(s >= 0 && !visited[s])
	{
		arr[addIndex] = s;
		visited[s] = true;
		addIndex++;
		//cout<< addIndex <<endl;
		while(addIndex != removeIndex)
		{
			s = arr[removeIndex];
			removeIndex++;
			cout<< rooms[s].name << " monster: " << rooms[s].monster << " strength: " << rooms[s].strength << " loot: " << rooms[s].treasure <<endl;
			for(v = nextNeighbor(s, 0); v < roomCap; v = nextNeighbor(s, v))
			{
				if(!visited[v])
				{
					arr[addIndex] = v;
					addIndex++;
					visited[v] = true;
				}
			}
			//cout<< removeIndex<<endl;
			
		}
	}
}

void Dungeon::unvisitAll()
{
	for(int i = 0; i < roomCap; i++)
	{
		visited[i] = false;
	}
}
//v is the vertex you want to find the next neighbor for
//w is the previous neighbor
uint Dungeon::nextNeighbor(uint v, uint w)
{
	//cout<< v << " " << w <<endl;
	for(int i = (w+1); i < roomCap; i++)
	{
		//cout<< v << " " << w << " "<< visited[i] << " " << adj[v][i] <<endl;
		if(adj[v][i] > 0)
		{
			//cout<<"return value: "<< i<<endl;
			return i;
		}
	}
	//cout<<"done"<<endl;
	return roomCap;
}