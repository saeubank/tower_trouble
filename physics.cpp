// Final project - game.cpp
// Generates and plays a tower defense game
// Jordan Dick
// jordan.dick@colorado.edu

#ifndef STDIncludes
#define STDIncludes
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
#endif

#include <iostream>

//#include "CSCIx229.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include "structures.h"
#include "objects.h"

using namespace std;


void physics(double *th, double *ph, double *dth, double *dph, double *zoom, float *Position)
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    keyboard(state);

    //adjust the eye position
    th += dth;
    ph += dph;
    zoom = zoom<2.0?2.0:zoom+dzoom;

    if (!pause)
    {
        //move the light
        ltheta += M_PI/180;
        ltheta = fmod(ltheta, 2*M_PI);
        Position[0] = 4.5*sin(ltheta);
        Position[2] = 4.5*cos(ltheta);

        //Manage the Spawning of Waves
        int newenemy = F.animate();
        if (newenemy)
        {
            int i = 0;
            while (enemies[i]!=NULL)
                ++i;
            enemies[i] = new Enemy(-8,6, F.currentwave==0 ? 25 : 25*F.currentwave, newenemy);
        }

        //animate enemies
        for (int i=0; i<64; ++i)
        {
            if (enemies[i] != NULL)
            {
                enemies[i]->animate();
            
                if (enemies[i]->x == 8.0 && enemies[i]->y == 6.0)
                {
                    F.lives -= 1;
                    delete enemies[i];
                    enemies[i] = NULL;
                    if (F.lives <= 0)
                        GameOver();
                }
            }
        }
        //animate towers
        for (int i=0; i<64; ++i)
        {
            if (towers[i] != NULL && !towers[i]->wireframe)
            {
                //select closest target
                float dist = INFINITY;
                for (int j=0; j<64; ++j)
                {
                    if (enemies[j] != NULL)
                    {
                        if (dist > towers[i]->distance(&enemies[j]))
                        {
                            dist = towers[i]->distance(&enemies[j]);
                            if (dist <= towers[i]->range)
                                towers[i]->target = &enemies[j];
                            else
                                towers[i]->target = NULL;
                        }
                    }
                }
                if (dist == INFINITY)
                    towers[i]->target = NULL;
                //manage firing loop
                if (towers[i]->cooldown < towers[i]->maxcooldown)
                    towers[i]->cooldown += 16;
                if (towers[i]->target != NULL && towers[i]->cooldown >= towers[i]->maxcooldown)
                {
                    Bullet* bullet = towers[i]->fire();
                    int k = 0;
                    while (bullets[k] != NULL)
                        ++k;
                    bullets[k] = bullet;
                    towers[i]->cooldown -= towers[i]->maxcooldown;
                }
                towers[i]->animate();
            }
        }
        //animate bullets
        for (int i=0; i<128; ++i)
        {
            if (bullets[i] != NULL)
            {
                if (*(bullets[i]->target) == NULL)
                {
                    delete bullets[i];
                    bullets[i] = NULL;
                }
                else
                {
                    bullets[i]->animate();
                    if (bullets[i]->distance() <= 0.5)
                    {
                        bullets[i]->collide();
                        if ((*bullets[i]->target)->health <= 0)
                        {
                            delete *(bullets[i]->target);
                            *(bullets[i]->target) = NULL;
                        }
                        delete bullets[i];
                        bullets[i] = NULL;
                    }
                }
            }
        }
    }
}
