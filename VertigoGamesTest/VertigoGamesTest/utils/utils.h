#ifndef __UTILS__
#define __UTILS__

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 960
#define WINDOW_CAPTION "Vertigo Games"
#define UNIT_SIZE 30

#define PLAYER 0

#define KEY_SPACE 32
#define KEY_ESC 27

typedef unsigned char       BYTE;

#define Lo(X) (BYTE)(X&0x00ff) 
#define Hi(X) (BYTE)((X>>8)&0x00ff)

#define UNEQUIPED	0
#define HEAD		1
#define RIGHTHAND	2
#define LEFTHAND	3

#define HAT			1
#define STONE		2
#define FLASHLIGHT	3
#define GUN			4
#define AMMO		5
#define LEVER		6


#define PI 3.1415926f

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius);

void print_bitmap_string(void * font, char * s, float x, float y);

#endif