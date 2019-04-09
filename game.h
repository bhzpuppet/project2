#ifndef _GAME_H_
#define _GAME_H_
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
bool init();
bool loadMedia();
void close();
void updatePosition();
void updatePosition_1();
void update_square (int a);
void check ();
void setposition();
void going();

#endif
