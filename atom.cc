
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
#include <string>
#include "models/bohr.h"
#include "models/rutherford.h"
#include "models/thompson.h"
#include "models/schrodinger.h"
#include "lib/reader.h"

using namespace std;

string model;
bohr Bohr;
rutherford Rutherford ;
thompson Thompson;
schrodinger Schrodinger;
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
  reader Reader;
  model = Reader.tipo();
  if( model == "bohr")
    Bohr = bohr(Reader.num());
  else if (model == "rutherford")
    Rutherford = rutherford(Reader.num());
  else if ( model == "thompson")
    Thompson = thompson(Reader.num());
  else if ( model == "schrodinger")
    Schrodinger = schrodinger(Reader.num());
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0,0.1,0.1,0,0,0,0,0.1,0);
  //    gluLookAt(0,0,1,0,0,0,0,0.1,0);
  if( model == "bohr")
    Bohr.draw();
  else if (model == "rutherford")
    Rutherford.draw();
  else if( model == "thompson")
    Thompson.draw();
  else if ( model == "schrodinger")
    Schrodinger.draw();
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
