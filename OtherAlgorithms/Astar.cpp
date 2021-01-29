#include <unordered_set>
#include <set>
#include<list>
#include <stdint.h>
class MapCell
{
public:
	bool Walkable;
	int x;
	int y;
};
class Square
{
public:
	MapCell oMapCell;
	Square* pParent;
	int F;
	int G;// A to current. line is 10, cross is 14
	int H;// current to B. columns and rows. column is 10, row is 10
};
class AStar
{
public:
	std::list<Square> openList;
	std::unordered_set<int64_t> openListCache;
	std::list<Square> closeList;
	std::unordered_set<int64_t> closeListCache;
	void CalculatePath(const std::vector<std::vector<MapCell>>& mapCells, const MapCell& A, const MapCell& B, std::list<MapCell>& result)
	{
		openList.push_back()
	}
};