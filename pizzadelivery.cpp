/**
*pizzadelivery.cpp
*
*"I pledge my honor that I have abided by the Stevens Honor System."
*
*Matthew Colozzo (c) 2015
*
*/
#include "Dungeon.h"
/*
*Pre-condition: A graph exists to traverse
*
*Post-condition: The halls and weights that would be used in this MST
*
*@param: 		none
*/
void Dungeon::mst()
{
	uint dest = 0;
	uint source = 0;
	uint maxSource = 0;
	uint maxDest = 0;
	uint maxValue = 0;
	uint counter = 1;
	unvisitAll();
	visited[source] = true;
	while(counter < roomCap)
	{
		maxValue = 0;
		for(source = 0; source < roomCap; source++)
		{
			for(dest =0; dest < roomCap; dest++)
			{
				//cout<< dest << " " << source << " " << !visited[dest] << " " << visited[source] <<endl;
				if(!visited[dest] && visited[source] && ((adj[source][dest]) + (adj[dest][source])) > 0)
				{
					//cout<< "dest " << dest << " source " << source <<endl;
					if(((adj[source][dest]) + (adj[dest][source])) > maxValue)
					{
						maxDest = dest;
						maxSource = source;
						maxValue = ((adj[source][dest]) + (adj[dest][source]));
					}
				}
			}
		}
		if(maxValue != 0)
		{
			cout<< rooms[maxSource].name << "--" << maxValue << "-->" << rooms[maxDest].name <<endl;
			visited[maxDest] = true;
		}
		else{
			cout<<"Graph is not connected"<<endl;
			return;
		}
		counter++;
	}
}
/*
*Pre-condition: A graph exists to traverse
*
*Post-condition: The path that will most easily acquire the heroes the most gold is found. 
*  				 starting from the given node index to every other node
*
*@param: 		uint start: the starting node you wish to find every lucrativePath from.
*/
void Dungeon:: lucrativePath(uint start)
{
	int *lootRatio = new int[roomCap];
	int *intvisited = new int[roomCap];
	int max = start;
	static const uint INF = -2147483646;
	for(int i = 0; i < roomCap; i++)
	{
		lootRatio[i] = INF;
		intvisited[i] = i;
	}
	lootRatio[start] = 0;
	int todo = roomCap;
	while(todo > 1)
	{
		for(int i = 0; i < todo; i++)
		{
			//cout << "lr at int i: " << lootRatio[intvisited[i]] <<endl;
			//cout << "lr at int max: " << lootRatio[intvisited[i]] << endl;
			if(lootRatio[intvisited[i]] > lootRatio[intvisited[max]] || ((lootRatio[intvisited[max]] == INF || max >= todo) && lootRatio[intvisited[i]] != INF))
			{
				//cout << "max before " << max <<endl;
				max = i;
				//cout << "max after " << max <<endl;
			}
		}
		
		swap(intvisited, max, --todo);
		
		for(int i = 0; i < todo; i++)
		{
			if(adj[intvisited[todo]][intvisited[i]] != 0)
			{
				if(lootRatio[intvisited[i]] == INF || (lootRatio[intvisited[i]] < lootRatio[intvisited[todo]] + ratioCalc(intvisited[i])))
				{
					//cout << todo <<endl;
					//cout << "i: " << i << "    " << "intvisited[i]: " << intvisited[i] <<endl;
					//cout << lootRatio[intvisited[i]] << " set equal to " << lootRatio[intvisited[todo]] + ratioCalc(i) <<endl;
					lootRatio[intvisited[i]] = lootRatio[intvisited[todo]] + ratioCalc(intvisited[i]);
				}
				
			}
		}
	}
	
	cout<< "From " << rooms[start].name <<endl;
	for(int i = 0; i < roomCap; i++)
	{
		if(i != start)
		{
			cout << rooms[i].name << " would have a loot ratio of: " << lootRatio[i] <<endl;
		}
	}
	
	
}

int* Dungeon::myDijkstra(uint s)
{
	int *lootRatio = new int[roomCap];
	int *intvisited = new int[roomCap];
	int max = s;
	static const uint INF = -2147483646;
	for(int i = 0; i < roomCap; i++)
	{
		lootRatio[i] = INF;
		intvisited[i] = i;
	}
	lootRatio[s] = 0;
	int todo = roomCap;
	while(todo > 1)
	{
		for(int i = 0; i < todo; i++)
		{
			//cout << "lr at int i: " << lootRatio[intvisited[i]] <<endl;
			//cout << "lr at int max: " << lootRatio[intvisited[i]] << endl;
			if(lootRatio[intvisited[i]] > lootRatio[intvisited[max]] || ((lootRatio[intvisited[max]] == INF || max >= todo) && lootRatio[intvisited[i]] != INF))
			{
				//cout << "max before " << max <<endl;
				max = i;
				//cout << "max after " << max <<endl;
			}
		}
		
		swap(intvisited, max, --todo);
		
		for(int i = 0; i < todo; i++)
		{
			if(adj[intvisited[todo]][intvisited[i]] != 0)
			{
				if(lootRatio[intvisited[i]] == INF || (lootRatio[intvisited[i]] < lootRatio[intvisited[todo]] + ratioCalc(intvisited[i])))
				{
					//cout << todo <<endl;
					//cout << "i: " << i << "    " << "intvisited[i]: " << intvisited[i] <<endl;
					//cout << lootRatio[intvisited[i]] << " set equal to " << lootRatio[intvisited[todo]] + ratioCalc(i) <<endl;
					lootRatio[intvisited[i]] = lootRatio[intvisited[todo]] + ratioCalc(intvisited[i]);
				}
				
			}
		}
	}
	return lootRatio;
}

/*
*Pre-condition: A graph exists to traverse
*
*Post-condition: A matrix is printed representing all the paths between each node that provide 
*		 		the most treasure
*
*@param: 		none
*/
void Dungeon::lucrativePaths()
{
	int** floydMat = new int*[roomCap];
	int i, j;
	
	for(i = 0; i < roomCap; i++)
	{
		floydMat[i] = myDijkstra(i);
	}
	
	
	
	for(i = 0; i  < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(floydMat[i][j] == -2147483646)
			{
				cout << "-" << " ";
			}
			else
			{
				cout<<floydMat[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

int Dungeon::ratioCalc(int roomInd)
{
	//cout << "loot ratio " << rooms[roomInd].treasure - rooms[roomInd].strength <<endl;
	return rooms[roomInd].treasure - rooms[roomInd].strength;
}


/*
*Pre-condition: A graph exists to traverse
*
*Post-condition: Performs a max flow algorithm from start to target, trying to deliver as many 
*				 pizzas as possible 
*				 between the two locations. Regardless of the possible paths found, 
*				 the heroes will only be able to afford as many pizzas as their budget allows.
*
*@param: 		uint start: The source node   uint target: The node you want to get to
				uint budget: The amount of treasure the heroes can spend (1:1 Treasure/Pizza Ratio)
*/
uint Dungeon::pizzaParty(uint start, uint target, uint budget)
{
	if(start == target)
	{
		cout << budget <<endl;
		return budget;
	}
	resNet = new uint*[roomCap];
	for(int i = 0; i < roomCap; i++)
	{
		resNet[i] = new uint[roomCap];
	}
	for(int i = 0; i < roomCap; i++)
	{
		for(int j = 0; j < roomCap; j++)
		{
			resNet[i][j] = adj[j][i];
		}
	}
	
	uint sum = 0; 
	while(true)
	{
		unvisitAll();
		uint temp = myPizza(target, start, budget);
		if(temp == 0)
		{
			if(sum > budget)
			{
				sum = budget;
			}
			cout << sum <<endl;
			return sum; 
		}
		else
		{
			sum += temp;
		}
	}
}
uint Dungeon::myPizza(uint start, uint target, uint budget)
{
	
	uint min;
	visited[start] = true;
	//cout << start << " " << target << " " << budget <<endl;
	if(start == target)
	{
		return budget;
	}
	
	for(int i = 0; i < roomCap; i++)
	{
		//cout << "i: " << i << " " << start << endl;
		if(!visited[i] && resNet[start][i] != 0)
		{
			//cout << "budget: " << budget << " resNet[start][i]: " << resNet[start][i] <<endl;
			if(budget < resNet[start][i])
			{
				min = budget;
			}
			else
			{
				min = resNet[start][i];
			}
			//cout << "min " << min <<endl;
			min = myPizza(i, target, min);
			if(min > 0)
			{
				resNet[start][i] -= min;
				resNet[i][start] += min;
				return min;
			}
			//cout << "hi;)" <<endl;
		}
	}
	return 0;
}