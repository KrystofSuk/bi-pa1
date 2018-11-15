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
  /* todo */
  unsigned long long int combs = 0;
  unsigned long long int tempLenght;
  length-=bulkhead;
  int same = 0;
  if(s1>s2){
    unsigned int st = s1;
    s1=s2;
    s2=st;
  }
  
  if(s1==s2){
    same = 1;
  }
  
  if(bulkhead > length){
    return 0;
  }

  unsigned int count = (length)/(s1+bulkhead);
  long long int overflow = 0;
  int f = 0;

  for(int i = 0; i <= count - overflow; i++){
    unsigned int temps1 = (s1+bulkhead)*(count) - (s1+bulkhead)*(i+overflow);
    unsigned int temps2 = (s2+bulkhead)*i;
    unsigned long long int tot = temps1 + temps2;
    
    
    if(tot == length){
      combs++;
        *c1 = temps1/(s1+bulkhead);
        *c2 = temps2/(s2+bulkhead);
        //printf("--\nTot: %llu = %u + %u\n ", tot, *c1,*c2);
      
      printf("--\nTot: %llu = %u + %u\n ", tot, temps1/(s1+bulkhead), temps2/(s2+bulkhead));
    }
printf("--\nTot: %llu = %u + %u\n ", tot, temps1/(s1+bulkhead), temps2/(s2+bulkhead));
    if(same == 1){
      break;
    }
    if(tot > length){
      unsigned long long int dif = tot - length;
      long long int cnt = (double)(dif)/(s1+bulkhead);
      //printf("Diff: %llu %lld\n",dif,cnt);
      overflow += cnt + 1;
      //printf("Overflow: %lld\n",overflow);
    }
  }
  printf("Je : %d \n",combs);

  return combs;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2;
  assert ( hyperloop ( 100, 4, 7, 0, &c1, &c2 ) == 4 && 4 * c1 + 7 * c2 + 0 * (c1 + c2 + 1) == 100 );

 // assert ( hyperloop ( 123456, 8, 3, 3, &c1, &c2 ) == 1871 && 8 * c1 + 3 * c2 + 3 * (c1 + c2 + 1) == 123456 );
 // assert ( hyperloop ( 127, 12, 8, 0, &c1, &c2 ) == 0 );
  assert ( hyperloop ( 127, 12, 4, 3, &c1, &c2 ) == 1 && 12 * c1 + 4 * c2 + 3 * (c1 + c2 + 1) == 127 );
 // assert ( hyperloop ( 100, 35, 0, 10, &c1, &c2 ) == 1  && c2 == 0 && 35 * c1 + 10 * (c1 + 1) == 100 );
 // assert ( hyperloop ( 110, 30, 30, 5, &c1, &c2 ) == 1 && 30 * c1 + 30 * c2 + 5 * (c1 + c2 + 1) == 110 );
  c1 = 2;
  c2 = 7;
 // assert ( hyperloop ( 110, 30, 30, 0, &c1, &c2 ) == 0 && c1 == 2 && c2 == 7 );
  c1 = 4;
  c2 = 8;
 // assert ( hyperloop ( 9, 1, 2, 10, &c1, &c2 ) == 0 && c1 == 4 && c2 == 8 );
  return 0;
}
#endif /* __PROGTEST__ */
