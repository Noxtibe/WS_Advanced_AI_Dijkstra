#include <iostream>
#include "Field.h"
#include "Nodes.h"

using namespace std;

int main(int argc, char* argv[])
{
	Field* field = nullptr;

	try
	{
		field = new Field();
	}
	catch(string& error)
	{
		cout << error << endl;
		return -1;
	}

	while (!field->IsCompleted())
	{
		field->Step();
	}
	cout << "Shortest path is " << field->GetShortestPathNodes().size() << " steps" << endl;

	return 0;
}