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
