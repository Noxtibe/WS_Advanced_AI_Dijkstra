#pragma once
#define FIELD_H

#include"Nodes.h"
#include <map>
#include <vector>

using FieldType = std::map<int, std::vector<Nodes*>>;

class Field
{

public :

	Field();
	~Field();

	void Reset();

private :

	void ClearData();
	void ParseInputFile();

public :

	static constexpr const char* INPUT_FILE = "../input.txt";

	int _rows;
	int _columns;
	FieldType _nodes;

	Nodes* _startNodes;
	Nodes* _targetNodes;

};

