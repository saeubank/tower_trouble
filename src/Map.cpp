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


Map::Map(int width, int height): width(width), height(height), map(width, std::vector<Tile>(height, Tile(TileType::GRASS))) {
	makeMap();
}

int Map::getWidth() const {
	return width;
}

int Map::getHeight() const {
	return height;
}

Tile & Map::operator[](Position pos) {
	return map[pos.x][pos.y];
}

const Tile & Map::operator[](Position pos) const {
	return map[pos.x][pos.y];
}

Tile Map::getTile(Position pos) const {
	return map[pos.x][pos.y];
}

void Map::setTile(Tile tile, Position pos) {
	map[pos.x][pos.y] = tile;
}

bool isEmpty(Position pos) {
	if (pos.x >= width || pos.x < 0 || pos.y >= height || y < 0) {
		return false;
	}
	return map[pos].tileType == TileType::GROUND;
}

bool setTower(TileType tower, Position pos) {
	if (isEmpty(pos)) {
		map[pos].tileType = TileType::tower;
		return true;
	}
	return false;
}

int getHValue(Position cur, Position end) {
	return std::abs(cur.x - end.x) + std::abs(cur.y - end.y);
}


std::vector<Position> AStar(Position start, Position end) {
	std::vector<Position> open;
	std::vector<Position> closed;
	open.push(start);

}

void Map::makeMap() {
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			if(i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				map[i][j].tileType = TileType::NOTHING;
			}
			else {
				map[i][j].tileType = TileType::GROUND;
			}
		}
	}
}
