/* @(#)reader.h
 */

#ifndef _READER_H
#define _READER_H 1


#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/* 
   Sebastian Arcila Valenzuela & Sergio Botero Uribe
   sebastianarcila@gmail.com sergiobuj@gmail.com
   2009-1
*/
struct reader
{
  
  reader()
  {
    const char *file = "config";
    freopen(file,"r",stdin);
  }
  string tipo();
  int num();
};
#endif /* _READER_H */

