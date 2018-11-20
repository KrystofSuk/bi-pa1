#ifndef __PROGTEST__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

unsigned long long int hyperloop                           ( unsigned long long int length,
                                                             unsigned int        s1,
                                                             unsigned int        s2,
                                                             unsigned int        s3,
                                                             unsigned int        bulkhead,
                                                             unsigned int      * c1,
                                                             unsigned int      * c2,
                                                             unsigned int      * c3 )
{
  unsigned long long int combs = 0;
  unsigned int lParts = 0;
  unsigned int sParts = 0;
  unsigned int mParts = 0;
  unsigned long long int tmpL = 0;
  if(bulkhead < 0){
    return 0;
  }
  if(length == 0){
    return 0;
  }
  //printf("%llu\n", length);
  if(length < bulkhead || (s1 <= 0 && s2 <= 0 && s3 <= 0)){
    if(bulkhead == length){
      *c1 = 0;
      *c2 = 0;
      *c3 = 0;
      return 1;
    }
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
  int sw2 = 0;
  if(s2 < s3){
    unsigned long long int st = s2;
    s2 = s3;
    s3 = st;
    sw2= 1;
  }
  if(s1 < s2){
    unsigned long long int st = s1;
    s1 = s2;
    s2 = st;
    sw= 2;
  }

  
  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  int f = 0;
  
  if(s2 == 0 && s3 == 0 && s1  != 0){
    while(tmpL < length){
      lParts++;
      tmpL += s1 + bulkhead;
    }
    if(tmpL == length){
      combs++;
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }  
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }    
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
    }
    
  //printf("C:%llu\n", combs);
    return combs;
  }

  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  
  if(s1 == 0 && s3 == 0 && s2 != 0){
    while(tmpL < length){
      mParts++;
      tmpL += s2 + bulkhead;
    }
    if(tmpL == length){
      combs++;
      
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }    
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }  
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
      //*c1 = sParts;
      //*c2 = 0;
      //printf("Got %u %u\n", *c1, *c2);
    }
    
  //printf("C:%llu\n", combs);
    return combs;
  }
  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  if(s2 == 0 && s1 == 0 && s3 != 0){
    while(tmpL < length){
      sParts++;
      tmpL += s3 + bulkhead;
    }
    if(tmpL == length){
      combs++;
      
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }  
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }    
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
      //*c1 = sParts;
      //*c2 = 0;
      //printf("Got %u %u\n", *c1, *c2);
    }
    
  //printf("C:%llu\n", combs);
    return combs;
  }

  if(s1 == s2 && s2 != s3){

    tmpL = 0;
    sParts = 0;
    lParts= 0;
    mParts = 0;

    if(s3 == 0){
      
      while(tmpL < length){
        mParts++;
        tmpL += s2 + bulkhead;
      }
      if(tmpL == length){
        combs++;
        
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }   
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }   
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
        //printf("ADD: %llu %u*%u %u*%u %u*%u = %u\n", tmpL, sParts,s3, mParts,s2, lParts,s1, (sParts*s3+mParts*s2+lParts*s1));
      }
      return combs;
    }

    while(tmpL < length){
      sParts++;
      tmpL += s3 + bulkhead;
    }

    //printf("Starting %llu %u %u %u\n", tmpL, sParts, mParts, lParts);

    
    while(1){
      
      if(tmpL == length){
        combs++;
        
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }   
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }   
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
        //printf("ADD: %llu %u*%u %u*%u %u*%u = %u\n", tmpL, sParts,s3, mParts,s2, lParts,s1, (sParts*s3+mParts*s2+lParts*s1));
      }
      
      if(sParts == 0){
        break;
      }
      tmpL += (s1 + bulkhead);    
      lParts ++;
      while( tmpL > length){      
        if(sParts > 0){
          tmpL-= (s3+bulkhead);
          sParts--;
        }else{
          break;
        } 
      }
    }
    
    //printf("Smaller: %d\n", combs);
    return combs;
  }

   if(s1 == s2 && s2 == s3){

    tmpL = 0;
    sParts = 0;
    lParts= 0;
    mParts = 0;

    if(s3 == 0){
      return 0;
    }

    while(tmpL < length){
      sParts++;
      tmpL += s3 + bulkhead;
    }

    //printf("Starting %llu %u %u %u\n", tmpL, sParts, mParts, lParts);

    if(tmpL == length){
      combs++;
      
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }   
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }   
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
      //printf("ADD: %llu %u*%u %u*%u %u*%u = %u\n", tmpL, sParts,s3, mParts,s2, lParts,s1, (sParts*s3+mParts*s2+lParts*s1));
    }
    
    
    //printf("Even: %d\n", combs);
    return combs;
  }
  
  if(s3 == 0 && s2 != 0 && s1 != 0){
    
    tmpL = 0;
    sParts = 0;
    lParts= 0;
    mParts = 0;
    while(tmpL < length){
      mParts++;
      tmpL += s2 + bulkhead;
    }


    
    printf("Starting %llu %u %u %u\n", tmpL, sParts, mParts, lParts);
    while(1){
      
      if(tmpL == length){
        combs++;
        
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = mParts;

          printf("%u %u %u \n", *c1, *c2, *c3);
        }  
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }    
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
        //printf("ADD: %llu %u*%u %u*%u %u*%u = %u\n", tmpL, sParts,s3, mParts,s2, lParts,s1, (sParts*s3+mParts*s2+lParts*s1));
      }
      
      if(mParts == 0){
        break;
      }
      tmpL += (s1 + bulkhead);    
      lParts ++;
      while( tmpL > length){      
        if(mParts > 0){
          tmpL-= (s2+bulkhead);
          mParts--;
        }else{
          break;
        } 
      }
    }
    
    //printf("WOW: %d\n", combs);
    return combs;
  }

  

  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  while(tmpL < length){
    mParts++;
    tmpL += s2 + bulkhead;
  }

  while(1){
    if(tmpL == length){
      combs++;
      if(f ==0 ){
        f=1;
        
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
          //printf("--");
        }  
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }    
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
      }
    }
    if(mParts == 0){
      break;
    }
    tmpL += (s1 + bulkhead);    
    lParts ++;
    while( tmpL > length){      
      if(mParts > 0){
        tmpL-= (s2+bulkhead);
        mParts--;
      }else{
        break;
      } 
    }
  }

  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  while(tmpL < length){
    lParts++;
    tmpL += s1 + bulkhead;    
  }
  if(tmpL == length){
    combs++;
    
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = mParts;
          *c2 = sParts;
          *c3 = lParts;
        }   
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }   
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
  }


  tmpL = 0;
  sParts = 0;
  lParts= 0;
  mParts = 0;
  while(tmpL < length){
    sParts++;
    tmpL += s3 + bulkhead;
  }

  while(1){
    if(sParts == 0){
      break;
    }
    
    unsigned int tmpsParts = sParts;
    while(sParts > 0){
      
      if(tmpL == length){
        combs++;     
        //printf("ADD: %llu %u*%u %u*%u %u*%u = %u\n", tmpL, sParts,s3, mParts,s2, lParts,s1, (sParts*s3+mParts*s2+lParts*s1));
      
      if(f ==0 ){
        
        f=1;
        
        if(sw == 1 && sw2 == 0){
          *c1 = mParts;
          *c2 = lParts;
          *c3 = sParts;
        }
        if(sw == 1 && sw2 == 1){
          *c1 = sParts;
          *c2 = lParts;
          *c3 = mParts;
        }
        if(sw == 0 && sw2 == 1){
          *c1 = lParts;
          *c2 = sParts;
          *c3 = mParts;
        }
        if(sw == 2 && sw2 == 1){
          *c1 = sParts;
          *c2 = mParts;
          *c3 = lParts;
        }      
        if(sw == 0 && sw2 == 0){
          *c1 = lParts;
          *c2 = mParts;
          *c3 = sParts;
        }
      }
      }
      tmpL += (s1 + bulkhead);
      lParts++;
      while( tmpL > length){      
        if(sParts > 0){
          tmpL-= (s3+bulkhead);
          sParts--;
        }else{
          break;
        } 
      }
    }
    lParts = 0;
    tmpL = tmpsParts*(s3+bulkhead) + mParts*(s2+bulkhead);
    sParts = tmpsParts;

    tmpL += (s2 + bulkhead);    
    mParts ++;
    while( tmpL > length){      
      if(sParts > 0){
        tmpL-= (s3+bulkhead);
        sParts--;
      }else{
        break;
      } 
    }
  }
  
  //printf("C:%llu %u %u %u\n", combs, *c1, *c2, *c3);
  return combs;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned int c1, c2, c3 = 0;
 
  assert(hyperloop ( 8580, 1, 2, 3, 1, &c1, &c2, &c3 )==1534390);
  printf("%u %u %u ", c1, c2, c3);
  printf("%u\n",(c1*1+c2*2+c3*3));
  
  assert ( hyperloop ( 100, 4, 7, 5, 0, &c1, &c2, &c3 ) == 42  && 4 * c1 + 7 * c2 + 5 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 100 );
  assert ( hyperloop ( 12345, 8, 3, 11, 3, &c1, &c2, &c3 ) == 82708 && 8 * c1 + 3 * c2 + 11 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 12345);
  c1 = 8;
  c2 = 9;
  c3 = 10;
  assert ( hyperloop ( 127, 12, 8, 10, 0, &c1, &c2, &c3 ) == 0 && c1 == 8 && c2 == 9 && c3 == 10 );
  assert ( hyperloop ( 127, 12, 8, 10, 3, &c1, &c2, &c3 ) == 4 && 12 * c1 + 8 * c2 + 10 * c3 + 3 * ( c1 + c2 + c3 + 1 ) == 127 );
  assert ( hyperloop ( 100, 35, 0, 0, 10, &c1, &c2, &c3 ) == 1 && c2 == 0 && c3 == 0 && 35 * c1 + 10 * ( c1 + 1 ) == 100);
  assert ( hyperloop ( 100, 35, 0, 35, 10, &c1, &c2, &c3 ) == 1 && c2 == 0 && 35 * c1 + 35 * c3 + 10 * ( c1 + c3 + 1 ) == 100);
  assert ( hyperloop ( 100, 35, 35, 35, 10, &c1, &c2, &c3 ) == 1 && 35 * c1 + 35 * c2 + 35 * c3 + 10 * ( c1 + c2 + c3 + 1 ) == 100 );
  c1 = 42;
  c2 = 43;
  c3 = 44;
  assert ( hyperloop ( 9, 1, 2, 3, 10, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
  
assert ( hyperloop ( 226, 0, 0, 0, 226, &c1, &c2, &c3 ) == 1 && 0 * c1 + 0 * c2 + 0 * c3 + 226 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 0, 0, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 0 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 226, 0, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 226 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 0, 226, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 0 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 0, 226, 226, 0, &c1, &c2, &c3 ) == 1 && 0 * c1 + 226 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 0, 226, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 0 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );
assert ( hyperloop ( 226, 226, 226, 226, 0, &c1, &c2, &c3 ) == 1 && 226 * c1 + 226 * c2 + 226 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 226 );

c1 = 42; c2 = 43; c3 = 44;
assert ( hyperloop ( 9, 0, 0, 0, -1, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 3, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 12, 12, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 12, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 12, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 0, 12, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 0, 12, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 12, 0, 0, 12, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 4, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 4, 0, 0, 3, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 0, 0, 0, 0, 0, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 0, 4, 5, 2, 7, &c1, &c2, &c3 ) == 0 && c1 == 42 && c2 == 43 && c3 == 44 );
assert ( hyperloop ( 9, 3, 2, 0, 0, &c1, &c2, &c3 ) == 2 && 3 * c1 + 2 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 3, 2, 14, 0, &c1, &c2, &c3 ) == 2 && 3 * c1 + 2 * c2 + 0 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 3, 3, 3, 0, &c1, &c2, &c3 ) == 1 && 3 * c1 + 3 * c2 + 3 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 9, 1, 1, 1, 0, &c1, &c2, &c3 ) == 1 && 1 * c1 + 1 * c2 + 1 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 9 );
assert ( hyperloop ( 99999999, 1, 1, 1, 0, &c1, &c2, &c3 ) == 1 && 1 * c1 + 1 * c2 + 1 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 99999999 );
assert ( hyperloop ( 99999999, 99999997, 0, 0, 1, &c1, &c2, &c3 ) == 1 && 99999997 * c1 + 0 * c2 + 0 * c3 + 1 * ( c1 + c2 + c3 + 1 ) == 99999999 );
assert ( hyperloop ( 1869, 623, 1246, 1246, 0, &c1, &c2, &c3 ) == 2 && 623 * c1 + 1246 * c2 + 1246 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
assert ( hyperloop ( 1869, 1246, 623, 1246, 0, &c1, &c2, &c3 ) == 2 && 1246 * c1 + 623 * c2 + 1246 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
assert ( hyperloop ( 1869, 1246, 1246, 623, 0, &c1, &c2, &c3 ) == 2 && 1246 * c1 + 1246 * c2 + 623 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1869 );
assert(hyperloop(1, 0, 0, 1, 1, &c1, &c2, &c3) == 1 && c1 == 0 && c2 == 0 && c3 == 0);
assert ( hyperloop ( 573, 0, 191, 382, 0, &c1, &c2, &c3 ) == 2 );

assert(hyperloop ( 1647, 0, 549, 1098, 0, &c1, &c2, &c3 ) == 2 && 0 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );
assert(hyperloop ( 1647, 1098, 549, 0, 0, &c1, &c2, &c3 ) == 2 && 1098 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );

assert(hyperloop ( 1647, 549, 0, 1098, 0, &c1, &c2, &c3 ) == 2 && 549 * c1 + 0 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );
assert(hyperloop ( 1647, 0, 549, 1098, 0, &c1, &c2, &c3 ) == 2 && 0 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );
assert(hyperloop ( 1647, 0, 549, 1098, 0, &c1, &c2, &c3 ) == 2 && 0 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );
assert(hyperloop ( 1647, 0, 549, 1098, 0, &c1, &c2, &c3 ) == 2 && 0 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );
assert(hyperloop ( 1647, 0, 549, 1098, 0, &c1, &c2, &c3 ) == 2 && 0 * c1 + 549 * c2 + 1098 * c3 + 0 * ( c1 + c2 + c3 + 1 ) == 1647 );


  
  return 0;
}
#endif /* __PROGTEST__ */
