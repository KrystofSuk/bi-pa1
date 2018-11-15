#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2 )
{
  //0.041s
  unsigned long long int combs = 0;
  int done = 0;
  unsigned int lParts = 0;
  unsigned int sParts = 0;
  unsigned long long int tmpL = 0;
  if(length < bulkhead){
    return 0;
  }
  length-=bulkhead;
  int sw= 0;
  if(s1 < s2){
    unsigned long long int st = s1;
    s1 = s2;
    s2 = st;
    sw= 1;
  }
  if(s1 == 0){
    while(tmpL < length){
      sParts++;
      tmpL += s2 + bulkhead;
    }
    if(tmpL == length){
      combs++;
      *c1 = 0;
      *c2 = sParts;
      printf("Got %u %u\n", *c1, *c2);
    }
    
  printf("C:%llu\n", combs);
  return combs;
  }
  if(s2 == 0){
    while(tmpL < length){
      sParts++;
      tmpL += s1 + bulkhead;
    }
    if(tmpL == length){
      combs++;
      *c1 = sParts;
      *c2 = 0;
      //printf("Got %u %u\n", *c1, *c2);
    }
    
  //printf("C:%llu\n", combs);
  return combs;
  }
  if(s1 == s2){
    while(tmpL < length){
      sParts++;
      tmpL += s2 + bulkhead;
    }
    if(tmpL == length){
      combs++;
      *c1 = sParts;
      *c2 = 0;
      //printf("Got %u %u\n", *c1, *c2);
    }
    
  //printf("C:%llu\n", combs);
  return combs;
  }
  while(tmpL < length){
    sParts++;
    tmpL += s2 + bulkhead;
  }
  while(done == 0){
    if(tmpL == length){
      combs++;
      if(sw == 0){
      *c1 = lParts;
      *c2 = sParts;
      }
      else{
      *c1 = sParts;
      *c2 = lParts;
      }
      //printf("Got %u %u\n", *c1, *c2);
    }
    if(sParts == 0){
      done = 1;
    }
    tmpL += (s1 + bulkhead);
    lParts ++;
    while( tmpL > length){
      tmpL-= (s2+bulkhead);
      sParts--;
    }
  }

  //printf("C:%llu\n", combs);
  return combs;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2;
  assert ( hyperloop ( 100, 4, 7, 0, &c1, &c2 ) == 4 && 4 * c1 + 7 * c2 + 0 * (c1 + c2 + 1) == 100 );
  
  assert ( hyperloop ( 20, 10, 5, 0, &c1, &c2 ) == 3);

  assert ( hyperloop ( 123456, 8, 3, 3, &c1, &c2 ) == 1871 && 8 * c1 + 3 * c2 + 3 * (c1 + c2 + 1) == 123456 );
  assert ( hyperloop ( 127, 12, 8, 0, &c1, &c2 ) == 0 );
  assert ( hyperloop ( 127, 12, 4, 3, &c1, &c2 ) == 1 && 12 * c1 + 4 * c2 + 3 * (c1 + c2 + 1) == 127 );
  assert ( hyperloop ( 100, 35, 0, 10, &c1, &c2 ) == 1  && c2 == 0 && 35 * c1 + 10 * (c1 + 1) == 100 );
  assert ( hyperloop ( 110, 30, 30, 5, &c1, &c2 ) == 1 && 30 * c1 + 30 * c2 + 5 * (c1 + c2 + 1) == 110 );
  c1 = 2;
  c2 = 7;
  assert ( hyperloop ( 110, 30, 30, 0, &c1, &c2 ) == 0 && c1 == 2 && c2 == 7 );
  c1 = 4;
  c2 = 8;
  assert ( hyperloop ( 9, 1, 2, 10, &c1, &c2 ) == 0 && c1 == 4 && c2 == 8 );
  return 0;
}
#endif /* __PROGTEST__ */
