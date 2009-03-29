#include "electron.h"
/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/

void draw_electron(point & i)
{
	
  gfloat &x0 = i.x, &y0 = i.y, &z0 = i.z, &teta = i.t, &r = i.r, &phi = i.p;
  x0 = r*cos(teta);
  y0 = r*sin(teta);
  z0 = r*cos(phi);

  GLUquadric *quadric = gluNewQuadric();	
	
  glPushMatrix();
  {
    if(r == 0)
      glColor3f(1,0,0);
    else if(r == 0.8)
      glColor3f(0.5,0.5,0.5);
    else
      glColor3f(0, 0, 0.8);
    glTranslatef(x0,y0,z0);    
    gluSphere(quadric, 0.025, 100, 100);
		
		
  }
  glPopMatrix();
  
  teta += 0.1;
  phi += 0.1;

  gluDeleteQuadric(quadric);
}

