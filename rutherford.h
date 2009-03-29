
#ifndef _RUTHERFORD_H
#define _RUTHERFORD_H 1

#include <vector>
#include "electron.h"

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
    int degree = 0, dd = 90;
    int zdegree = 360, zdd = -90;
    for(int i = 0; i<n; ++i,r+=dr, degree+=dd,zdegree += zdd)
      system.push_back(point(0,0,0, r, degree, zdegree));
    
    
  }
  void  draw();
};




#endif /* _RUTHERFORD_H */

