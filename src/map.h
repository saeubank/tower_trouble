#include "objects.h"

#ifndef map_H
#define map_H

class Map
{
    int arr[81] = {0, 0, 0, 0, 0, 0, 0, 0, 0,  // it's a 2nd order Hilbert curve
                      -1,-1,-1,-1, 0,-1,-1,-1,-1,
                        0, 0, 0,-1, 0,-1, 0, 0, 0,
                        0,-1,-1,-1, 0,-1,-1,-1, 0,
                        0,-1, 0, 0, 0, 0, 0,-1, 0,
                        0,-1, 0,-1,-1,-1, 0,-1, 0,
                        0,-1, 0,-1, 0,-1, 0,-1, 0,
                        0,-1,-1,-1, 0,-1,-1,-1, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0};
    int waves[9][10] = {{2, 2, 2, 2, 2, 0, 0, 0, 0, 0},
                              {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                              {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                              {2, 1, 2, 1, 2, 1, 2, 1, 2, 1},
                              {2, 2, 2, 2, 2, 1, 1, 1, 1, 1},
                              {3, 0, 3, 0, 3, 0, 3, 0, 3, 0},
                              {3, 2, 1, 3, 2, 1, 3, 2, 1, 3},
                              {3, 3, 3, 3, 2, 2, 2, 1, 1, 1},
                              {3, 3, 3, 3, 3, 3, 3, 3, 3, 3}};
    int wavetime = 600;
    int currentwavetime = 0;
    int spawncount = -1;
public:
    int lives = 20;
    int currentwave = -1;
    Map();
    void tile(float x, float y, float z, int direction);
    void render();
    int animate();
    void spawnwave();
    int getlocation(float ex, float ey);
};

#endif


#include <vector>

struct Position {
	int x, y;
	Position(int x, int y): x(x), y(y) {}
};

enum class TileType {
	NOTHING,
	GROUND,
	TOWER1,
	TOWER2,
};

struct Tile {
	TileType tileType;
	Tile(TileType tileType): tileType(tileType) {}
};

// from http://www.redblobgames.com/pathfinding/a-star/implementation.html
template<typename T, typename priority_t>
struct PriorityQueue {
  typedef pair<priority_t, T> PQElement;
  priority_queue<PQElement, vector<PQElement>,
                 std::greater<PQElement>> elements;

  inline bool empty() const { return elements.empty(); }

  inline void put(T item, priority_t priority) {
    elements.emplace(priority, item);
  }

  inline T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};

class Map {
	int width, height;
	std::vector<std::vector<Tile>> map;

	void makeMap();

	public:
		Map(int width, int height);
		int getWidth() const;
		int getHeight() const;
		Tile & operator[](Position pos);
		const Tile & operator[](Position pos) const;
		Tile getTile(Position pos) const;
		void setTile(Tile tile, Position pos);
		bool isEmpty(Position pos);
		bool setTower(TileType tower, Position pos);
};
