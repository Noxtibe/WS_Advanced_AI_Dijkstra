#include "Nodes.h"

Nodes::Nodes(int x, int y, bool obstacle, bool start, bool target): _x(x), _y(y), _isObstacle(obstacle), _isStart(start), _isTarget(target)
{

}

bool Nodes::isObstacle() const
{
	return _isObstacle;
}

bool Nodes::isStart() const
{
	return _isStart;
}

bool Nodes::isTarget() const
{
	return _isTarget;
}

int Nodes::GetGCost() const
{
	return _gCost;
}

int Nodes::GetHCost() const
{
	return _hCost;
}

int Nodes::GetFCost() const
{
	return _gCost + _hCost;
}

int Nodes::GetX() const
{
	return _x;
}

int Nodes::GetY() const
{
	return _y;
}

Nodes* Nodes::GetParent() const
{
	return _parent;
}

void Nodes::SetCost(int g, int h)
{
	_gCost = g;
	_hCost = h;
}

void Nodes::SetParent(Nodes* parent)
{
	_parent = parent;
}
