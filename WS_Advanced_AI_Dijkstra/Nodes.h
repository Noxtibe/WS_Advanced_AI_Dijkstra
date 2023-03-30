#pragma once
#define NODES_H

class Nodes
{

public:

	Nodes();
	Nodes(int x, int y, bool obstacle, bool start, bool target);
	~Nodes() = default;

	bool isObstacle() const;
	bool isStart()const;
	bool isTarget()const;

private:

	bool _isObstacle;
	bool _isStart;
	bool _isTarget;

	int _x;
	int _y;

};