/* 
   For the equidistribution on the sphere 
   look at sphere_equi.dvi
 */
#ifndef _THOMPSON_H
#define _THOMPSON_H 1

#include <vector>
#include "electron.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

gfloat randfloat(gfloat low, gfloat high);

struct thompson
{
  vector<point> system;
  point proton;
  int n;
  gfloat dt;
  gfloat dp;
  thompson(){}
  thompson(int N)
  {
    dt = 0;
    dp = 0;
    n = N;
    proton = point(0 ,0 ,0 , 0, 0 ,0);
    
    
  }
  void  draw();
};


#endif /* _THOMPSON_H */

