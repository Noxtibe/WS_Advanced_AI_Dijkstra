#pragma once
#define NODES_H

class Nodes
{

public:

	//Nodes();
	Nodes(int x, int y, bool obstacle, bool start, bool target);
	~Nodes() = default;

	bool isObstacle() const;
	bool isStart()const;
	bool isTarget()const;

	int GetGCost() const;
	int GetHCost() const;
	int GetFCost() const;
	int GetX() const;
	int GetY() const;
	Nodes* GetParent() const;

	void SetCost(int g, int h);
	void SetParent(Nodes* parent);

	inline bool operator<(const Nodes& other) const
	{
		const int fCost = GetFCost();
		const int otherFCost = other.GetFCost();
		return fCost < other.GetFCost() || fCost == otherFCost && _gCost < other.GetGCost();
	}

private:

	bool _isObstacle;
	bool _isStart;
	bool _isTarget;

	int _x;
	int _y;

	int _gCost = 0;
	int _hCost = 0;
	Nodes* _parent = nullptr;
};