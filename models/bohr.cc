#include "bohr.h"
void bohr::draw(unsigned int tex)
{
    draw_electron(proton, dt, dp, tex);
    for(int i = 0; i<system.size(); ++i)
      draw_electron(system[i],dt,dp,tex);
}


