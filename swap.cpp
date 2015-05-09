#include "Dungeon.h"

/*
*Pre-condition: an array and the two indices containing the values to be swapped
*Post-condition: the two values in the array will be properly swapped
*
*@param 		arr - the array holding the values to be swapped x - the first index to swap 
* 				y - the other index to swap
*/
void Dungeon::swap(int*& arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void Dungeon::swap(Hero*& arr, int x, int y)
{
	Hero temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
