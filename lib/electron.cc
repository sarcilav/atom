#include "electron.h"
#include <iostream>
using namespace std;
#define D(XX) cerr<<#XX<<" "<<XX<<endl
/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/

void draw_electron(point & i, gfloat &dt,  gfloat &dp, const gfloat & R)
{
	
  gfloat &x0 = i.x, &y0 = i.y, &z0 = i.z, &teta = i.t, &r = i.r, &phi = i.p;
  
  x0 = r*cos(teta);
  y0 = r*sin(teta);
  D((int)phi%360);
  GLUquadric *quadric = gluNewQuadric();	
  
  glPushMatrix();
  {
    if(r == 0)
      glColor3f(1,0,0);
    else
      glColor3f(0, 0, 1);
    glRotatef((int)phi%360,1,1,0);
    glTranslatef(x0,y0,z0);    
    gluSphere(quadric, R, 100, 100);  
		
  }
  glPopMatrix();
  
  teta += dt;
  
  gluDeleteQuadric(quadric);
}
