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
