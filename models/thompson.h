/* 
   For the equidistribution on the sphere 
   look at sphere_equi.dvi
 */
#ifndef _THOMPSON_H
#define _THOMPSON_H 1

#include <vector>
#include "../lib/electron.h"

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
    dt = 0.1;
    dp = 0.1;
    n = N;
    proton = point(0 ,0 ,0 , 0, 0 ,0);
    gfloat r = 0.2;
    gfloat degree = 0, dd = PI/4;
    for(int i = 0; i<n; ++i,degree+=dd)
      system.push_back(point(0,0,0, r, degree, rand()));    
    
  }
  void  draw(unsigned int );
};


#endif /* _THOMPSON_H */

