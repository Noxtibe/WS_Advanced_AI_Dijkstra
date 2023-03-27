#include <iostream>
#include "limits.h" // Needed for infinity

using namespace std;

#define size 7 // Define the size of the matrice

// 

int main()
{
	int graph[size][size] = 
	{ {0, 1, 7, 6, 0, 0, 0}, {1, 0, 9, 0, 0, 3, 0},
	{7, 9, 0, 0, 0, 0, 1}, {6, 0, 0, 0, 2, 0, 0},
	{0, 0, 0, 2, 0, 0, 0}, {0, 3, 0, 0, 0, 0, 3},
	{0, 0, 0, 0, 5, 3, 0} };
}

// 

void dijkstra(int graph[size][size], int source)
{
	int distance[size];
	bool passed[size];
	int origin[size];

	for (int i = 0; i < size; i++)
	{
		origin[0] = -1;
		distance[i] = INT_MAX;
		passed[i] = false;
	}

	distance[source] = 0;
	for (int i = 0; i < size ; i++)
	{
		int U = minDistance(distance, passed);
		passed[U] = true;
		for (int j = 0; j < size; j++)
		{
			//int actualDistance
		}
	}

}

// 

int minDistance(int distance[], bool passed[])
{
	int min = INT_MAX; // INFINITY
	int indexMin = INT_MAX; // INFINITY

	for (int i = 0; i < size; i++)
	{
		if (!passed[i] && distance[i] <= min)
		{
			min = distance[i];
			indexMin = i;
		}
	}
	return indexMin;
}

//

void PathOrigin(int origin[], int i)
{
	if (origin[i] == -1)
	{
		return;
	}
	PathOrigin(origin, origin[i]);
	cout << i + 1 << " ";
}


