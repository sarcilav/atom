#ifndef _ELECTRON_H
#define _ELECTRON_H 1


#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#endif

#include<stdio.h>
#include <math.h>

typedef GLfloat gfloat;
const gfloat PI = 2*acos(0);


/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/


struct point
{
  gfloat x;
  gfloat y;
  gfloat z;
  gfloat r;
  gfloat t;
  gfloat p;
  point(){}
  point(gfloat X, gfloat Y, gfloat Z, gfloat R, gfloat T, gfloat P)
  {
    x = (X);
    y = (Y);
    z = (Z);
    r = R;
    t = T;
    p = P;
  }
	
};

void draw_electron(point & i,  gfloat & dt, gfloat & dp,unsigned int tex, const gfloat & R = 0.025);
#endif /* _ELECTRON_H */

