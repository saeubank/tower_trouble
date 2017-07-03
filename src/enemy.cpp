#include "enemy.h"

Enemy::Enemy(float X, float Y, int Health, int Type)
{
    type = Type;
    health = Health;
    x = X;
    y = Y;
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
    movestate = 0;
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
    
    //Follow the metal grey road
    switch (movestate)
    {
    case 0:
        if (x >= -2.0)
        {  movestate = 1; dx = 0; dy = -speed;}
        break;
    case 1:
        if (y <= 2.0)
        {  movestate = 2; dx = -speed; dy = 0;}
        break;
    case 2:
        if (x <= -6.0)
        {  movestate = 3; dx = 0; dy = -speed;}
        break;
    case 3:
        if (y <= -6.0)
        {  movestate = 4; dx = speed; dy = 0;}
        break;
    case 4:
        if (x >= -2.0)
        {  movestate = 5; dx = 0; dy = speed;}
        break;
    case 5:
        if (y >= -2.0)
        {  movestate = 6; dx = speed; dy = 0;}
        break;
    case 6:
        if (x >= 2.0)
        {  movestate = 7; dx = 0; dy = -speed;}
        break;
    case 7:
        if (y <= -6.0)
        {  movestate = 8; dx = speed; dy = 0;}
        break;
    case 8:
        if (x >= 6.0)
        {  movestate = 9; dx = 0; dy = speed;}
        break;
    case 9:
        if (y >= 2.0)
        {  movestate = 10; dx = -speed; dy = 0;}
        break;
    case 10:
        if (x <= 2.0)
        {  movestate = 11; dx = 0; dy = speed;}
        break;
    case 11:
        if (y >= 6.0)
        {  movestate = 12; dx = speed; dy = 0;}
        break;
    case 12:
        if (x >= 8.0)
        {  x = 8.0; y = 6.0; }
        break;
    default:
        movestate = 0;
        break;
    }
}

void Enemy::damage(int dmg)
{
    health -= dmg;
}
