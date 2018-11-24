#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

/*Vzato z example http://www.cplusplus.com/reference/cstdlib/qsort/ dokumentaci ke qsortu*/
int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

/**
 * @brief is funtion for reading input
 * 
 * @param pos is array of ints for positions
 * @param cnt is count of positions
 * @return int is 0 for bad input or 1 for good
 */
int inputs(int pos[], int * cnt)
{  
  int index = 1;
  printf("Mozna umisteni:\n");

  if(scanf(" { %d", &pos[0])!=1  && pos[0] < 1)
  {
      return 0;
  }
  
  while(1){
    if(index == 1000000){
      break;
    }

    int t = scanf(" , %d",&pos[index]);

    if(t == 0){
      char c;
      scanf("%c",&c);

      if(c != '}'){
        return 0;
      }
      break;
    }

    if(pos[index] < 1){
        return 0;
    }
    index++;
  }
  *cnt = index;
  return 1;
}

/**
 * @brief This function is selecting and counting best billboard positions
 * 
 * @param pos is array of possible positions
 * @param ref is array of best selected positions
 * @param count is number of possible positions 
 * @param dif is maximum distance between two positions
 * @return int is best position count or error (-1)
 */
int countBillboards(int pos[], int ref[], int count, int dif){
  int lastDif = 0;
  int cnt = 0;

  for(int i = 1; i < count; i++){
    
    if(pos[i]-pos[i-1] > dif)
      return -1;
    
    lastDif += pos[i]-pos[i-1];
    printf("%d-%d / %d %d\n",pos[i],pos[i-1], lastDif, dif);
    if(lastDif > dif){  
      cnt++;
      ref[cnt+2] = pos[i-1];
      lastDif = pos[i]-pos[i-1];
    }
    
  }
  return cnt;
}

/**
 * @brief is function for calculating shortest distance between two billboards
 * 
 * @param pos is array of possible positions
 * @param ref is array of best selected positions
 * @param count is number of possible positions 
 * @param req is required number of billboards
 * @return int is minimum lenght between bilboards  
 */
int distanceBillboards(int pos[], int ref[], int count, int req){
  int dist = -1;
  int f = -1;

  for(int i = 0; i < count; i++)
    ref[i] = INT_MAX;

  ref[0]=pos[0];
  ref[1]=pos[count-1];
  
  if(req == 2)
    return ref[1]-ref[0];

  for(int i =  pos[count-1]; i >= 0; i--){
    for(int t = 0; t < count; t++)
      ref[t] = INT_MAX;
    
    ref[0]=pos[0];
    ref[1]=pos[count-1];
    
    int res = countBillboards(pos, ref, count, i);
    printf("-----\n");
    for(int x = 0; x < res; x++)
      printf("%d\n",ref[x]);
    printf("-----\n");
    if(res > 0)
      res+=2;
    
    if(res == req){
      f=1;
    }
  }

  if(f==1){
    int smal = ref[1]-ref[0];

    qsort(ref, count, sizeof(int), compare);    
       
      
    for(int x = 1; x < req; x++)
      if(smal > ref[x]-ref[x-1])
        smal = ref[x]-ref[x-1];
    
    dist = smal;
  }
  
  return dist;
}

int main (void){  
  static int pos [1000000];
  static int refPos [1000000];
  int count = 0;


  if(inputs(pos, &count)==0){    
    printf("Nespravny vstup.\n");
    return 0;
  }

  qsort(pos, count, sizeof(int), compare);
  for(int i =0; i< count;i++){
   // printf("%d , ", pos[i]);
  }
  printf("Pocet billboardu:\n");

  while(1){
    int req = 0;

    if(scanf("%d",&req)!=1){       
      if(feof(stdin)==0){         
        printf("Nespravny vstup.\n");
      }
      break;
    }

    if(req<=1 ){
      printf("Vzdalenost: inf\n");
    }
    else if(req > count){
      printf("N/A\n");
    }else{
      int len = distanceBillboards(pos,refPos,count,req);
      printf("Vzdalenost: %d\n", len);
    }
  }
  return 0;
}