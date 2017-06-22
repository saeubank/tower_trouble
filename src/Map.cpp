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
	priority_queue<tuple<Position, int, double>, std::vector<Position, int, double>, greater<Position, int, double>>> open;
	open.push(start, cost, getHValue(start, end));
	while (!open.empty()) {
		auto cur = frontier.get();
		if (cur == end) {
			return path;
		}
		for (auto next : )
	}

}


// int AStarFindPath(const int nStartX, const int nStartY,
// 		  const int nTargetX, const int nTargetY,
// 		  const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
// 		  int* pOutBuffer, const int nOutBufferSize) {
//
//   auto idx = [nMapWidth](int x, int y) {
//     return x + y*nMapWidth;
//   };
//
//   auto h = [=](int u) -> int { // lower bound distance to target from u
//     int x = u % nMapWidth, y = u / nMapWidth;
//     return abs(x-nTargetX) + abs(y-nTargetY);
//   };
//
//   const int n = nMapWidth*nMapHeight;
//   const int startPos = idx(nStartX, nStartY), targetPos = idx(nTargetX, nTargetY);
//
//   int discovered = 0; ExploredNodes = 0;
//   vector<int> p(n), d(n, INT_MAX);
//   priority_queue<tuple<int, int, int>,
// 		 vector<tuple<int, int, int>>,
// 		 greater<tuple<int, int, int>>> pq; // A* with tie breaking
//   d[startPos] = 0;
//   pq.push(make_tuple(0 + h(startPos), 0, startPos));
//   while (!pq.empty()) {
//     int u = get<2>(pq.top()); pq.pop(); ExploredNodes++;
//     for (auto e : {+1, -1, +nMapWidth, -nMapWidth}) {
//       int v = u + e;
//       if ((e == 1 && (v % nMapWidth == 0)) || (e == -1 && (u % nMapWidth == 0)))
// 	continue;
//       if (0 <= v && v < n && d[v] > d[u] + 1 && pMap[v]) {
// 	p[v] = u;
// 	d[v] = d[u] + 1;
// 	if (v == targetPos)
// 	  goto end;
// 	pq.push(make_tuple(d[v] + h(v), ++discovered, v));
//       }
//     }
//   }
//  end:
//
//   if (d[targetPos] == INT_MAX) {
//     return -1;
//   } else if (d[targetPos] <= nOutBufferSize) {
//     int curr = targetPos;
//     for (int i = d[targetPos] - 1; i >= 0; i--) {
//       pOutBuffer[i] = curr;
//       curr = p[curr];
//     }
//     return d[targetPos];
//   }
//
//   return d[targetPos]; // buffer size too small
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
