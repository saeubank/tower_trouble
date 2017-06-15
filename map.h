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
