#include "Field.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Field::Field()
{
	ParseInputFile();
}

Field::~Field()
{
	ClearData();
}

void Field::Step()
{
	if (_isCompleted || _openSet.size() < 1)
	{
		return;
	}

	// Algo
	Nodes* currentNode = _openSet.at(0);

	for (Nodes* n : _openSet)
	{
		if (*n < *currentNode)
		{
			currentNode = n;
		}
	}

	_openSet.erase(std::remove(_openSet.begin(), _openSet.end(), currentNode), _openSet.end());
	_closedSet.push_back(currentNode);

	if (currentNode == _targetNodes)
	{
		OnCompleted();
		return;
	}

	// Neighbours nodes
	vector<Nodes*> neighbourNodes = GetNeighbourNodes(currentNode);

	for (Nodes* neighbour : neighbourNodes)
	{
		if (neighbour->isObstacle() || count(_closedSet.begin(), _closedSet.end(), neighbour))
		{
			continue;
		}

		bool neighbourInOpen = count(_openSet.begin(), _openSet.end(), neighbour);
		int newCost = currentNode->GetGCost() + GetDistanceBetweenNodes(currentNode, neighbour);

		if (newCost < neighbour->GetGCost() || !neighbourInOpen)
		{
			neighbour->SetCost(newCost, GetDistanceBetweenNodes(neighbour, _targetNodes));
			neighbour->SetParent(currentNode);
			if (!neighbourInOpen)
			{
				_openSet.push_back(neighbour);
			}
		}
	}
}

void Field::Reset()
{
	ClearData();
	ParseInputFile();
}

bool Field::IsCompleted() const
{
	return _isCompleted;
}

bool Field::GetRows() const
{
	return _rows;
}

bool Field::GetColumns() const
{
	return _columns;
}

const std::vector<Nodes*>& Field::GetShortestPathNodes() const
{
	return _shortestPathNodes;
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
	_openSet.clear();
	_closedSet.clear();
	_shortestPathNodes.clear();

	_rows = 0;
	_columns = 0;
	_startNodes = nullptr;
	_targetNodes = nullptr;
	_isCompleted = false;
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

	while (getline(inFile, line))
	{
		if (!firstLineLoaded)
		{
			firstLineLoaded = true;
			stringstream ss(line);
			ss >> _rows;
			ss >> _columns;
		}
		else 
		{
			vector<Nodes*> nodeRow;
			stringstream ss(line);

			char nodeVal;

			for (int i = 0; i < _columns; i++)
			{
				bool obstacle = false;
				bool isStart = false;
				bool isTarget = false;
				int x = row;
				int y = i;

				ss >> nodeVal;

				switch (nodeVal)
				{
					case '0': // Walkable nodes

						break;

					case '1': // Obstacles nodes
						obstacle = true;
						break;

					case 'S': // Starting nodes
						isStart = true;
						break;

					case 'T': // Target nodes
						isTarget = true;
						break;

					default:
						throw string("Unknown character found while parsing the file: ") + to_string(nodeVal);
				}

				Nodes* n = new Nodes(x, y, obstacle, isStart, isTarget);
				if (nodeVal == 'S')
				{
					if (_startNodes != nullptr)
					{
						throw string("Duplicate starting node found. Check the input file.");
					}
					_startNodes = n;
				}

				if (nodeVal == 'T')
				{
					if (_targetNodes != nullptr)
					{
						throw string("Duplicate target node found. Check the input file.");
					}
					_targetNodes = n;
				}

				nodeRow.push_back(n);
			}
			_nodes[row] = nodeRow;
			++row;
		}	
	}
	_openSet.push_back(_startNodes);
	cout << "Loaded " << _rows << " rows and " << _columns << " columns" << endl;
}

void Field::OnCompleted()
{
	_isCompleted = true;
	Nodes* current = _targetNodes;
	while (current != _startNodes)
	{
		current = current->GetParent();
		_shortestPathNodes.push_back(current);
	}
}

std::vector<Nodes*> Field::GetNeighbourNodes(Nodes* currentNode)
{
	vector<Nodes*> neighbours;

	const int currentX = currentNode->GetX();
	const int currentY = currentNode->GetY();

	// Top
	if (currentX > 0)
	{
		neighbours.push_back(_nodes[currentX - 1].at(currentY));
	}

	// Left
	if (currentY > 0)
	{
		neighbours.push_back(_nodes[currentX].at(currentY - 1));
	}

	// Right
	if (currentY < _columns - 1)
	{
		neighbours.push_back(_nodes[currentX].at(currentY + 1));
	}

	// Down
	if (currentX < _rows - 1)
	{
		neighbours.push_back(_nodes[currentX + 1].at(currentY));
	}

	return neighbours;
}

int Field::GetDistanceBetweenNodes(const Nodes* n1, const Nodes* n2) const
{
	return std::abs(n1->GetX() - n2->GetX()) + std::abs(n1->GetY() - n2->GetY());
}
