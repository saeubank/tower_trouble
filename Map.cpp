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
		bool canPlaceTower(Position pos);
		bool setTower(TileType tower, Position pos);
		bool containsPath(Position start, Position end);
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

bool canPlaceTower(Position pos) {
	return map[pos].tileType == TileType::GROUND;
}

bool setTower(TileType tower, Position pos) {
	if (canPlaceTower(pos)) {
		map[pos].tileType = TileType::tower;
		return true;
	}
	return false;
}

bool containsPath(Position start, Position end) {
	std::std::vector<Position> prev;
	return containsPathRec(prev, start, end);
}

bool containsPathRec(std::vector<Position> prev, Position current, Position end) {
	Position up = Position(start.x - 1, start.y);
	Position down = Position(start.x + 1, start.y);
	Position left = Position(start.x, start.y - 1);
	Position right = Position(start.x, start.y + 1);
	bool state = false;
	bool inPrev = false;
	if (up.x >= 0 && up != prev) {
		if (up == end) {
			return true;
		}
		for (int i = 0; !inPrev && i < prev.length(); i++) {
			if (up == prev[i]) {
				inPrev = true;
			}
		}
		if (!inPrev) {
			state = containsPathRec(prev.push_back(current), up, end);
			inPrev = false;
		}
	}
	if (!state && down.x < map.getWidth()) {
		if (down == end) {
			return true;
		}
		for (int i = 0; !inPrev && i < prev.length(); i++) {
			if (down == prev[i]) {
				inPrev = true;
			}
		}
		if (!inPrev) {
			state = containsPathRec(prev.push_back(current), down, end);
			inPrev = false;
		}
	}
	if (!state && left.y >= 0) {
		if (left == end) {
			return true;
		}
		for (int i = 0; !inPrev && i < prev.length(); i++) {
			if (left == prev[i]) {
				inPrev = true;
			}
		}
		if (!inPrev) {
			state = containsPathRec(prev.push_back(current), left, end);
			inPrev = false;
		}
	}
	if (!state && right.y < map.getHeight()) {
		if (right == end) {
			return true;
		}
		for (int i = 0; !inPrev && i < prev.length(); i++) {
			if (right == prev[i]) {
				inPrev = true;
			}
		}
		if (!inPrev) {
			state = containsPathRec(prev.push_back(current), right, end);
			inPrev = false;
		}
	}
	return state;
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
