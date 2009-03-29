//#include "atom.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
/* 
   Sebastian Arcila Valenzuela
   sebastianarcila@gmail.com
   2009
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <stdarg.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>

using namespace std;

/* DEBUG */
#define D(x) cerr<<__LINE__<<" "#x" "<<x<<endl
#define D_v(x) for(int i=0;i<x.size();cerr<<x[i++]<<" ")

#define ALL(x) x.begin(),x.end()

typedef GLfloat gfloat;

struct point
{
  gfloat x;
  gfloat y;
  gfloat z;
  gfloat r;
  gfloat t;
  point(){}
  point(gfloat X, gfloat Y, gfloat Z, gfloat R, gfloat T)
  {
    x = (X);
    y = (Y);
    z = (Z);
    r = R;
    t = T;
  }
  
};



vector<point> electron;
GLUquadric *quadric = gluNewQuadric();
void init()
{
  glClearColor(0, 0, 0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);

  /*machete proton*/  electron.push_back(point(0,0,0,0, 0));
  electron.push_back(point(0,0,0,0.2, 0));
  electron.push_back(point(0,0,0,0.4, 180));
  electron.push_back(point(0,0,0,0.6, 270));
}


void draw_electron(GLfloat &x0, GLfloat &y0,GLfloat &z0, GLfloat &teta,const GLfloat & r)
{
  
  
  x0 = r*cos(teta);
  y0 = r*sin(teta);


  glPushMatrix();
  {
    if(r == 0)
      glColor3f(1,0,0);
    else
      glColor3f(0, 0, 0.8);
    glTranslatef(x0,y0,z0);    
    gluSphere(quadric, 0.025, 100, 100);

  }
  teta += 0.1;
  glPopMatrix();

  
}




void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  for(int i = 0; i<electron.size(); ++i)
    draw_electron(electron[i].x, electron[i].y, electron[i].z, electron[i].t, electron[i].r);

  glutSwapBuffers();
  
}

void reshape(int W, int H)
/*           largo  ancho */
{

}


void keyboard(unsigned char key, int a , int b)
{
}
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (600, 600);
  glutCreateWindow(argv[0]);

  init();
  glutReshapeFunc(reshape);
  glutDisplayFunc(&display);
  glutIdleFunc(display);
  

  glutKeyboardFunc (keyboard);

  glutMainLoop();

  return 0; 
}
