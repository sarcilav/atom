
#include "bohr.h"
void bohr::draw()
{
  
  draw_electron(proton, dt, dp);
  for(int i = 0; i<system.size(); ++i)
    draw_electron(system[i],dt,dp);
}


