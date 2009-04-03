#include "thompson.h"
void thompson::draw(unsigned int tex)
{
  draw_electron(proton, dt, dp,tex,0.2);
  for(int i = 0; i<system.size(); ++i)
    draw_electron(system[i],dt,dp,tex);
}
