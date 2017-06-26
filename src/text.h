#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
#include <string>

#ifndef STDIncludes
#include <cstdlib>
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif
#endif

#ifndef text_h
#define text_h


void RenderText(std::string message, SDL_Color color, int x, int y, int size, SDL_Window* window);

#endif
