
#include "rutherford.h"
void rutherford::draw()
{
  
  draw_electron(proton, dt, dp,0.2);
  for(int i = 0; i<system.size(); ++i)
    draw_electron(system[i],dt,dp);
}


