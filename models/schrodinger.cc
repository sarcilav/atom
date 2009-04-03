#include "schrodinger.h"
void draw_elec(point & i, const gfloat &dt,const gfloat & dp,unsigned int tex, const gfloat & R)
{
  gfloat &x0 = i.x, &y0 = i.y, &z0 = i.z, &teta = i.t, &r = i.r, &phi = i.p;
  
  x0 = r*cos(teta);
  y0 = r*sin(teta);
  GLUquadric *quadric = gluNewQuadric();	
  
  glPushMatrix();
  {
    
    glColor3f(0, 0, 1);
    glTranslatef(x0,y0,z0);    
    glTranslatef(-sin(phi)/10,cos(phi)/10,0);    
    gluSphere(quadric, R, 100, 100);  
  
    

  }
  glPopMatrix();
  
  teta += dt;
  phi += dp*4;
  gluDeleteQuadric(quadric);
}




void schrodinger::draw(unsigned int tex)
{
  draw_electron(proton, dt, dp,tex);
  for(int i = 0; i<system.size(); ++i)
    draw_elec(system[i],dt, dp,tex, 0.02);
}


