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

	void Step();
	void Reset();

	bool IsCompleted() const;
	bool GetRows() const;
	bool GetColumns() const;
	const std::vector<Nodes*>& GetShortestPathNodes() const;

private :

	void ClearData();
	void ParseInputFile();
	void OnCompleted();

	std::vector<Nodes*> GetNeighbourNodes(Nodes* currentNode);
	int GetDistanceBetweenNodes(const Nodes* n1, const Nodes* n2) const;

public :

	static constexpr const char* INPUT_FILE = "../input.txt";

	int _rows;
	int _columns;
	FieldType _nodes;

	Nodes* _startNodes = nullptr;
	Nodes* _targetNodes = nullptr;

	std::vector<Nodes*> _openSet;
	std:: vector<Nodes*> _closedSet;
	

	bool _isCompleted = false;

	std::vector<Nodes*> _shortestPathNodes;
};

