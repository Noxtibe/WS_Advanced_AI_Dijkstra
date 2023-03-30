#include "Field.h"
#include <iostream>
#include <fstream>

using namespace std;

Field::Field()
{
	ParseInputFile();
}

Field::~Field()
{
	ClearData();
}

void Field::Reset()
{
	ClearData();
	ParseInputFile();
}

void Field::ClearData()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		vector<Nodes*>& row = _nodes.at(i);

		for (Nodes* n : row)
		{
			delete n;
		}
		row.clear();
	}
	_nodes.clear();
	_startNodes = nullptr;
	_targetNodes = nullptr;
}

void Field::ParseInputFile()
{
	ifstream inFile(INPUT_FILE);
	string line;

	bool firstLineLoaded = false;
	int row = 0;

	if (!inFile.is_open())
	{
		throw string("Unable to read the input file");
	}
}
