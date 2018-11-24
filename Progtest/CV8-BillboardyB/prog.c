#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct point{
  int value;
  int amount;
};

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
int inputs(struct point pos[], int * cnt, int * am)
{  
  int index = 1;
  int total = 0;
  printf("Mozna umisteni:\n");

  if(scanf(" { %d", &pos[0].value)!=1  || pos[0].value < 0)
  {
      return 0;
  }
  pos[0].amount = 1;
  total++;
  while(1){
    if(index == 1000000){
      break;
    }
    int inp = -1;
    int t = scanf(" , %d",&inp);
    qsort(pos, index, sizeof(struct point), compare);

    if(t != 0){
      total++;
      int added = 0;
      for(int i = 0; i < index; i++){
        if(inp == pos[i].value){
          pos[i].amount++;
          added = 1;
          break;
        }
      }
      if(added == 0){
        pos[index].value = inp;
        pos[index].amount = 1;
        index++;
      }
    }

    if(t == 0){
      char c;
      scanf("%c",&c);

      if(c != '}'){
        return 0;
      }
      break;
    }
    if(inp < 0){
        return 0;
    }


  }
  *am = total;
  *cnt = index;
  return 1;
}

int getPivoted(struct point pos[], int count, double pivot){
  int dif = INT_MAX;
  int val = -1;
  for(int i = 1; i < count-1; i++){
    if(abs(pivot - (double)pos[i].value) < dif){
      val = pos[i].value;
      dif = abs(pivot - pos[i].value);
    }else{
      break;
    }
  }
  return val;
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
int distanceBillboards(struct point pos[], int ref[], int count, int req){
  int dist = -1;
  
  double pivot = ((double)(pos[count-1].value-pos[0].value)/(req-1.0));
  
  ref[0]=pos[0].value;
  int index= 1;
  for(int i = 1; i < req -1; i++){

    double next = pivot*(i)+(double)pos[0].value;
    int tmp = getPivoted(pos, count, next);
    
    if(ref[index-1]!=tmp){
      ref[index] = tmp;
      index++;
    }
  }
  index++;
  ref[index-1]=pos[count-1].value;
  int smal = ref[index-1]-ref[0];
          
  for(int x = 1; x < index; x++){
    if(smal > ref[x]-ref[x-1]){
      smal = ref[x]-ref[x-1];
    }
  }
      
  dist = smal;
  return dist;
}

int main (void){  
  static struct point pos [1000000];
  static int refPos [1000000];
  int count = 0;
  int totalAmount = 0;


  if(inputs(pos, &count, &totalAmount)==0 || count == 0){    
    printf("Nespravny vstup.\n");
    return 0;
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
    if(req < 0){
      printf("Nespravny vstup.\n");
      break;
    }
    if(req<=1 ){
      printf("Vzdalenost: inf\n");
    }
    else if(req > totalAmount){
      printf("N/A\n");
    }else if(req > count){
      printf("Vzdalenost: 0\n");
    }else{
      int len = distanceBillboards(pos,refPos,count,req);
      printf("Vzdalenost: %d\n", len);
    }
  }
  return 0;
}