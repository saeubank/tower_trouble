#include "objects.h"

#ifndef enemy_h
#define enemy_h

class Enemy
{
public:
   float x, y, z, dx, dy, theta, speed;
   //float a, b, c, w;
   int health, type;
   float s1, s2, ds1, ds2;
   int movestate;

   Enemy(float X, float Y, int Health, int Type);
   void render();
   void animate();
   void damage(int dmg);
};

#endif
