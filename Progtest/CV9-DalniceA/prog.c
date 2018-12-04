#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


typedef struct{
  long long int position;
  long long int distance;
  double tolls [26];
} GATE;

typedef struct{
  double tolls [26];
} TOLLS;

GATE* inputGates(GATE* gates, int * size){ 
  int siz = 1;
  int max = 10;
  GATE * RES = (GATE *)malloc(max * sizeof(*RES));
  double val = -1;  
  char c = ' ';
  if(scanf(" %c", &c) !=1 || c != '{'){
    *size = -1;    
    free(RES);
    return NULL;
  }
  
  for(int j = 0; j < 26; j++)
    RES[siz-1].tolls[j] = -1;
  
  long long int dist = 0;
  while(1){    
    if(scanf(" [ %lld : %c = %lf", &RES[siz-1].position, &c, &val)!=3 || RES[siz-1].position <= 0){
      
        //printf("%d/%d\n",siz,INT_MAX);
      *size = -1;      
      free(RES);
      return NULL;
    }
    dist += RES[siz-1].position;
    RES[siz-1].distance = dist;
    if(siz != 1)
      for(int j = 0; j < 26; j++)
        RES[siz-1].tolls[j] = RES[siz-2].tolls[j];

    if((int)c >= 65 && (int)c <= 90){
      RES[siz-1].tolls[(int)c-65] = val;
    }else{
      *size = -1;      
      free(RES);
      return NULL;
    }

    while(scanf(" , %c = %lf", &c, &val)==2){
      
      if((int)c >= 65 && (int)c <= 90){
        RES[siz-1].tolls[(int)c-65] = val;
      }else{
        
        *size = -1;
        free(RES);
        return NULL;
      }
    }

    if(scanf(" ] %c",&c)==1){
      if(c == ','){
        if(siz == max){
          GATE* TMP = (GATE*)malloc((siz*2)*sizeof(*TMP));
          for(int i = 0; i < siz;i++){
            TMP[i] = RES[i];
          }
          free(RES);
          RES=TMP;
          max = siz*2;
        }
        siz++;
        
      }else if(c == '}'){
        *size = siz;
        return RES;
      }else{
        *size = -1;        
        free(RES);
        return NULL;
      }
    }
  }

  *size = siz;
  return RES;
}


int getSegment(GATE* gates, int size, int pos){
  long long int total = 0;
  for(int i = 0; i < size; i++){
    total += gates[i].position;
    if(total >= pos){
      return i;
    }
  }
  return -1;
}

long long int gateTotalPos(GATE* gates, int index){
  return gates[index].distance;
}

TOLLS processPath(GATE* gates,  int size, long long int start, long long int end){
  TOLLS res;
  for(int i = 0; i < 26; i++){
    res.tolls[i] = 0;
  }
  long long int currentPos = start;
  long long int distance = 0;
  int segmentS = getSegment(gates, size, start);
  int segmentE = getSegment(gates, size, end); 
  
  long long int tmp = 0; 
  long long int segmentPos = gates[getSegment(gates, size, start)-1].distance; 
  long long int segmentPosMax = gates[getSegment(gates, size, start)].distance; 
  int segmentIndex = getSegment(gates,size,start);
  int t = 0;
  int dir = 1;
  int switched = 0;
  long long int current = start;
  if(start < end){
    segmentIndex = getSegment(gates,size,start);
    for(int i = start; i <= end; i++){
      if(segmentPosMax < end){        
        distance = segmentPosMax-current;
        for(int tm = 0; tm < 26; tm++){        
          if(gates[segmentIndex].tolls[tm] != -1)
            res.tolls[tm] += gates[segmentIndex].tolls[tm]*distance;
        }
        i = segmentPosMax;
        current = segmentPosMax;
        //printf("D: %lld %d\n", distance, current);
      }
      else{
        distance = end-current;
        //printf("E: %lld\n", distance);
        for(int tm = 0; tm < 26; tm++){        
          if(gates[segmentIndex].tolls[tm] != -1)
            res.tolls[tm] += gates[segmentIndex].tolls[tm]*distance;
        }
        i = end;
      }
      if(i == segmentPosMax){
        //printf("Next segment\n");
        t++;
        //printf("S:%lld %lld %d\n", segmentPos, segmentPosMax, getSegment(gates, size, start));
        segmentPos = gates[getSegment(gates, size, start)-1+t].distance; 
        segmentPosMax =  gates[getSegment(gates, size, start)+t].distance; 
        //printf("S:%lld %lld %d\n", segmentPos, segmentPosMax, getSegment(gates, size, start));
        segmentIndex+=dir;
      }    
    } 
  }

  
  if(start > end){

    segmentIndex = getSegment(gates,size,end)+1;
    for(int i = start; i > end; i--){
      
      if(segmentPos > end){        
        distance = current-segmentPos;
        for(int tm = 0; tm < 26; tm++){        
          if(gates[segmentIndex].tolls[tm] != -1)
            res.tolls[tm] += gates[segmentIndex].tolls[tm]*distance;
        }
        current = segmentPos;
        i = current;
        //printf("D: %lld %d\n", distance, current);
      }
      else{
        distance = current-end;
        //printf("E: %lld\n", distance);
        for(int tm = 0; tm < 26; tm++){        
          if(gates[segmentIndex].tolls[tm] != -1)
            res.tolls[tm] += gates[segmentIndex].tolls[tm]*distance;
        }
        i = 0;
      }
      if(i == segmentPos){
        //printf("Next segment\n");
        t--;
        //printf("S:%lld %lld %d\n", segmentPos, segmentPosMax, getSegment(gates, size, start));
        segmentPos = gates[getSegment(gates, size, start)-1+t].distance; 
        segmentPosMax =  gates[getSegment(gates, size, start)+t].distance; 
        //printf("S:%lld %lld %d\n", segmentPos, segmentPosMax, getSegment(gates, size, start));
        segmentIndex--;
      }    
    }

  }


/*
  if(segmentS < segmentE){
    currentPos = start;
    for(int i = segmentS; i < segmentE; i++){
      tmp = gateTotalPos(gates, i);
      distance = tmp-currentPos;
      currentPos = tmp;
    
      for(int tm = 0; tm < 26; tm++){        
        if(gates[i].tolls[tm] != -1)
          res.tolls[tm] += gates[i].tolls[tm] * distance;
      }
    }    
    distance = end-currentPos;
  
    for(int tm = 0; tm < 26; tm++){        
      if(gates[segmentE].tolls[tm] != -1)
        res.tolls[tm] += gates[segmentE].tolls[tm] * distance;
    }
  }else if( segmentS == segmentE){
    
    distance = end-start;
    for(int tm = 0; tm < 26; tm++){        
      if(gates[segmentE].tolls[tm] != -1)
        res.tolls[tm] += gates[segmentE].tolls[tm] * distance;
    }

  }else if(segmentS > segmentE){
    currentPos = start;
    for(int i = segmentS; i > segmentE; i--){
      tmp = gateTotalPos(gates, i-1);
      distance = currentPos-tmp;
      currentPos = tmp;
      for(int tm = 0; tm < 26; tm++){        
        if(gates[i].tolls[tm] != -1)
          res.tolls[tm] += gates[i].tolls[tm] * distance;
      }
    }    
    distance = currentPos-end;
  
    for(int tm = 0; tm < 26; tm++){        
      if(gates[segmentE].tolls[tm] != -1)
        res.tolls[tm] += gates[segmentE].tolls[tm] * distance;
    }
  }
  */
  return res;
}

int main (void){ 
  int size = 1;   
  GATE* gates = NULL;
  printf("Myto:\n");
  gates = inputGates(gates, &size);
  //printf("%d\n",size);
  if(size == -1){
    printf("Nespravny vstup.\n");
    free(gates);
    return 0;
  }
  long long int start = 0;
  long long int end = 0;
  printf("Hledani:\n");
  while(scanf("%lld %lld", &start, &end)==2){
    if(start == end || start < 0 || end < 0 || start > gateTotalPos(gates,size-1) || end > gateTotalPos(gates,size-1)){
      printf("Nespravny vstup.\n");
      free(gates);
      return 0;
    }
    TOLLS toll = processPath(gates, size, start, end);
    
    
      
      printf("%lld - %lld:",start,end);
      int quote = 0;
      
      for(int i = 0; i < 26; i++){
        if(toll.tolls[i]!=0){
          if(quote){
            printf(",");
          }
          printf(" %c=%f",i+65, toll.tolls[i]);     
          quote = 1;     
        }
      }
      
      printf("\n");
  }
  if(!feof(stdin)){
    printf("Nespravny vstup.\n");
  } 
  free(gates);
  return 0;
}