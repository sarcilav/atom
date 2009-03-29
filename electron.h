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

#include <math.h>
/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/
typedef GLfloat gfloat;

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

void draw_electron(point & i, const gfloat & dt, const gfloat & dp);
#endif /* _ELECTRON_H */

