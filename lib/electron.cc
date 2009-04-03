#include "electron.h"
void draw_electron(point & i,  gfloat &dt,  gfloat &dp, unsigned int tex,const gfloat & R)
{
	
  gfloat &x0 = i.x, &y0 = i.y, &z0 = i.z, &teta = i.t, &r = i.r, &phi = i.p;
  
  x0 = r*cos(teta);
  y0 = r*sin(teta);
  z0 = r*cos(phi);
  GLUquadric *quadric = gluNewQuadric();	
	
  glPushMatrix();
  {
    if(r == 0)
      {
	
	glEnable(GL_COLOR);
	glColor3f(1,0,0);
      }
    else
      {

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
	glColor3f(0,0,1);
	gluQuadricTexture(quadric,GL_TRUE);
      }
    glRotatef(phi,1,0,0);
    glTranslatef(x0,y0,0);
    
    gluSphere(quadric, R, 100, 100);  
    glDisable(GL_COLOR);    
    glDisable(GL_TEXTURE_2D);

  }
  glPopMatrix();
  teta += dt;
  
  gluDeleteQuadric(quadric);
}

