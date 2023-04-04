/*#include <iostream>
#include "limits.h" // Needed for infinity

/*using namespace std;

#define size 7 // Define the size of the matrice

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

// Main code

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
	for (int i = 0; i < size - 1; i++)
	{
		int U = minDistance(distance, passed);
		passed[U] = true;
		for (int j = 0; j < size; j++)
		{
			int actualDistance = distance[U] + graph[U][j];
			if (!passed[j] && graph[U][j] && actualDistance < distance[j])
			{
				origin[j] = U;
				distance[j] = actualDistance;
			}
		}
	}
	cout << "Vertex\t\tDistance\tPath" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << source + 1 << "--->" << i + 1 << "\t\t" << distance[i] << "\t\t" << source + 1 << " ";
		PathOrigin(origin, i);
		cout << endl;
	}
}

// Matrices

int main() {
	int graph[size][size] = { {0, 1, 7, 6, 0, 0, 0}, {1, 0, 9, 0, 0, 3, 0},
							 {7, 9, 0, 0, 0, 0, 1}, {6, 0, 0, 0, 2, 0, 0},
							 {0, 0, 0, 2, 0, 0, 0}, {0, 3, 0, 0, 0, 0, 3},
							 {0, 0, 0, 0, 5, 3, 0} };
	dijkstra(graph, 0);
}*/


