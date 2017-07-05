#include "enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int X, int Y, int Health, int Type, Map f)
{
    F = &f;
    type = Type;
    health = Health;
    cur.first = X;
    cur.second = Y;
    x = 2.0*cur.first - F->getWidth();
    y = 2.0*cur.second - F->getHeight();
    z = 2;
    theta = 0.0;
    speed = 0.06;
    if (type == 1)
    {
        speed = 0.08;
        health /= 2;
    }
    else if (type == 3)
    {
        speed = 0.04;
        health *= 2;
    }
    dx = speed; dy = 0;

    if (type == 2)
    {
        s1 = 0.85;  ds1 = 0.02;
        s2 = 0.85;  ds2 = -0.02;
    }
    else if (type == 1)
    {
        s1 = 0.8;  ds1 = 0.03;
        s2 = 0.8;  ds2 = -0.03;
    }
    else //type == 3
    {
        s1 = 0.0;    ds1 = 5.12;
        s2 = 0.0;    ds2 = 3.0;
    }
}

void Enemy::render()
{
    float emission[] = {0.0,0.0,0.0,1.0};

    //glColor3f(1.0,1.0,1.0);
    if (type == 2)
    {
        glColor3f(0.8,0.0,0.8);
        //glColor3f(0.0,0.8,0.0);
        emission[0] = 0.4; emission[1] = 0.0; emission[2] = 0.4;
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        dodecahedron(x, z, -y, theta+16.6666, s1);

        glColor3f(0.0,0.0,1.0);
        //glColor3f(1.0,1.0,0.0);
        emission[0] = 0.0; emission[1] = 0.0; emission[2] = 0.6;
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        icosahedron(x, z, -y, theta, s2);
    }
    else if (type == 1)
    {
        glColor3f(0.8,0.0,0.0);
        //glColor3f(0.0,0.8,0.8);
        emission[0] = 0.5; emission[1] = 0.0; emission[2] = 0.0;
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        cube(x, z, -y, theta, s1*0.8);

        glColor3f(0.6,0.4,0.0);
        //glColor3f(0.4,0.6,1.0);
        emission[0] = 0.5; emission[1] = 0.3; emission[2] = 0.0;
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        octahedron(x, z, -y, theta, s2);
    }
    else // type == 3
    {
        glColor3f(0.0,0.8,0.8);
        emission[0] = 0.0;    emission[1] = 0.4;emission[2] = 0.25;
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);

        sphere(x, z, -y, 0, 0.25);

        glPushMatrix();
        glTranslated(x, z, -y);
        glRotated(theta, 0,1,0);
        glRotated(s1, 1,0,0);
        torus (0, 0, 0, 0.100, 0.4);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x, z, -y);
        glRotated(theta/2, 0,-1,0);
        glRotated(s2, 1,0,0);
        torus (0, 0, 0, 0.100, 0.65);
        glPopMatrix();
    }
}

void Enemy::animate()
{
    // geometry rendering
    if (type == 2)
    {
        if (s1 <= 0.7 || s1 >= 1.0)
            ds1 = -ds1;
        if (s2 <= 0.7 || s2 >= 1.0)
            ds2 = -ds2;
        theta += 2; theta = fmod(theta, 360.0);
    }
    else if (type == 1)
    {
        if (s1 <= 0.5 || s1 >= 1.1)
            ds1 = -ds1;
        if (s2 <= 0.5 || s2 >= 1.1)
            ds2 = -ds2;
        theta += 2; theta = fmod(theta, 360.0);
    }
    else //type == 3
    {
        theta += 2; theta = fmod(theta, 720.0);
        s1 = fmod(s1, 360.0);
        s2 = fmod(s2, 360.0);
    }
    s1 += ds1;
    s2 += ds2;

    x += dx; y += dy;
    
    //Pathfinding
    cout << cur.first << " " << cur.second << " " << (cur.first*2.0 - F->getWidth()) << " " << (cur.second*2.0 - F->getHeight()) << endl;
    if (x - (cur.first*2.0  - F->getWidth())  >= 2.0 ||
        y - (cur.second*2.0 - F->getHeight()) >= 2.0)
    {
        cur = nxt;
        nxt = F->AStar(cur, Position(F->getWidth()-1, F->getHeight()-1))[1];
        dx = (nxt.first-cur.first) * speed;
        dy = (nxt.second-cur.second) * speed;
    } 
}

void Enemy::damage(int dmg)
{
    health -= dmg;
}
