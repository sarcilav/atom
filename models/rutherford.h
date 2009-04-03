#ifndef _RUTHERFORD_H
#define _RUTHERFORD_H 1

#include <vector>
#include "../lib/electron.h"

#include <time.h>
#include <stdlib.h>
using namespace std;

struct rutherford
{
  vector<point> system;
  point proton;
  int n;
  gfloat dt;
  gfloat dp;
  rutherford(){}
  rutherford(int N)
  {

    dt = 0.1;
    dp = 0.1;
    n = N;
    proton = point(0 ,0 ,0 , 0, 0 ,0);
    gfloat r = 0.2,dr =0.2;
    gfloat degree = 0, dd = PI/2;
    for(int i = 0; i<n; ++i,r+=dr, degree+=dd)
      system.push_back(point(0,0,0, r, degree, rand()));
    
    
  }
  void draw(unsigned int );
};




#endif /* _RUTHERFORD_H */

