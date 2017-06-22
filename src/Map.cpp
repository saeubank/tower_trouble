#include "Map.hpp"
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>

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

bool Map::isEmpty(Position pos) {
	if (pos.x >= width || pos.x < 0 || pos.y >= height || y < 0) {
		return false;
	}
	return map[pos].tileType == TileType::GROUND;
}

bool Map::setTower(TileType tower, Position pos) {
	if (isEmpty(pos)) {
		map[pos].tileType = TileType::tower;
		return true;
	}
	return false;
}

double getHValue(Position cur, Position end) {
	return sqrt(pow((cur.x - end.x), 2) + pow((cur.y - end.y), 2));
}


std::vector<Position> AStar(Position start, Position end) {
	std::vector<Position> closed;
	int cost = 0;
	//priority_queue<tuple<Position, double>, std::vector<Position, double>, greater<Position, double>>> open;
	PriorityQueue<Position, double> open;
	open.put(start, getHValue(start, end));
	unordered_map<Position, Position> came_from;
    unordered_map<Position, double> cost_so_far;
	came_from[start] = start;
    cost_so_far[start] = 0;

	while (!open.empty()) {
		auto cur = open.get();
		if (cur == end) {
			return path;
		}
		for (auto next : )
	}

}

//   while (!frontier.empty()) {
//     auto current = frontier.get();
//
//     if (current == goal) {
//       break;
//     }
//
//     for (auto& next : graph.neighbors(current)) {
//       double new_cost = cost_so_far[current] + graph.cost(current, next);
//       if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {
//         cost_so_far[next] = new_cost;
//         double priority = new_cost + heuristic(next, goal);
//         frontier.put(next, priority);
//         came_from[next] = current;
//       }
//     }
//   }
// }

void Map::makeMap() {
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			map[i][j].tileType = TileType::GROUND;
			// if(i == 0 || i == width - 1 || j == 0 || j == height - 1) {
			// 	map[i][j].tileType = TileType::NOTHING;
			// }
			// else {
			// 	map[i][j].tileType = TileType::GROUND;
			// }
		}
	}
}
