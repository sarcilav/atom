
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

/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/
#include "electron.h"

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

vector<point> electron;

void init()
{
  glClearColor(0, 0, 0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
	
  /* model for light */

  gfloat a[] = { 1.0, 0.0, 0.0, 0.0 };
  gfloat d[] = { 1.0, 0.0, 0.0, 0.0 };
  gfloat p[] = { 1.0, 0.0, 0.0, 0.0 };
  gfloat lma[] = { 0.4, 0.4, 0.4, 1.0 };
  gfloat lv[] = { 0.0 };
  glLightfv(GL_LIGHT0, GL_AMBIENT, a);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
  glLightfv(GL_LIGHT0, GL_POSITION, p);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lma);
  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lv);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  
  /*machete proton*/  electron.push_back(point(0,0,0,0, 0,0));
  electron.push_back(point(0,0,0,0.2, 0,360));
  electron.push_back(point(0,0,0,0.4, 90,270));
  electron.push_back(point(0,0,0,0.6, 180,180));
  electron.push_back(point(0,0,0,0.6, 270,90));
  electron.push_back(point(0,0,0,0.8, 360,0));
  
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0,0.1,0.1,0,0,0,0,0.1,0);
  for(int i = 0; i<electron.size(); ++i)
    draw_electron(electron[i]);
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
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
