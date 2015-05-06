/**
*am.cpp
*
*"I pledge my honor that I have abided by the Stevens Honor System."
*
*Matthew Colozzo (c) 2015
*
*/
#include "Dungeon.h"

void Dungeon::makeMatrix(uint n)
{
	this->n = n;
	visited = new bool [n];
	adj = new uint* [n];
	for(int i = 0; i < n; i++)
	{
		adj[i] = new uint [n];
				
		for(int j = 0; j < n; j++)
		{
			adj[i][j] = 0;
		}
	}
}
/*
*Pre-condition: the source node, destination node, and the desired weight of the edge
*
*Post-condition: Sets the edge between the two edges
*
*@param: 		origin - the source node, destin- the destination node, cap - the weight of the edge
*/
bool Dungeon::setHall(uint origin, uint destin, uint cap)
{
	if(origin > n || destin > n || origin < 0|| destin < 0 || origin == destin)
	{
		cout<<"Invalid edge!\n";
		return false;
	}
	else{
		adj[origin][destin] = cap;
		return true;
	}
}
/*
*Pre-condition: Halls exist to show
*
*Post-condition: Printed matrix
*
*@param: 		none
*/
void Dungeon::showHalls()
{	
	int i, j;
	
	for(i = 0; i  < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}