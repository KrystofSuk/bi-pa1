#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int inputs(int pos [], int * len, int * cnt)
{  
  printf("Mozna umisteni:\n");
  if(scanf(" %d", len)!=1 || *len <= 0)
  {
      return 0;
  }
  if(scanf(" : { %d", &pos[0])!= 1 || pos[0] >= *len|| pos[0] < 1){
      return 0;
  }
  int index = 1;
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
    if(pos[index] >= *len || pos[index] < 1){
        return 0;
    }
    index++;
  }
  *cnt = index;
  return 1;
}

/*Vzato z example http://www.cplusplus.com/reference/cstdlib/qsort/ dokumentaci ke qsortu*/
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int countBillboards(int pos[], int len, int count, int dif){
  //check podminek okraju
  int lastDif = 0;
  int cnt = 0;
  for(int i = 1; i < count; i++){
    if(pos[i]-pos[i-1] > dif){
      return -1;
    }
    lastDif += pos[i]-pos[i-1];
    
    //printf("L %d %d %d %d\n", cnt, i,dif,lastDif);
    if(lastDif > dif){  
      
      //printf("CNT\n");    
      cnt++;
      lastDif = pos[i]-pos[i-1]; 
    }
  }
  return cnt;
}

int main (void)
{  
  int len = 0;
  //jeste chybi 1000000
  static int pos [1000000];
  int count = 0;
  if(inputs(pos, &len, &count)==0){    
    printf("Nespravny vstup.\n");
    return 0;
  }
  pos[count]=0;
  count++;
  qsort(pos, count, sizeof(int), compare);
  if(pos[count]!=len){      
    pos[count]=len;
    count++;
  }
  for(int i = 0; i<count; i++){
    //printf("%d\n",pos[i]);
  }
  printf("Vzdalenosti:\n");
  while(1){
    int dif = 0;
    if(scanf("%d",&dif)!=1){       
      if(feof(stdin)==0){         
        printf("Nespravny vstup.\n");
      }
      break;
    }
    if(dif<=0){
      printf("Nespravny vstup.\n");
      break;
    }
    int cnt = countBillboards(pos,len,count,dif);
    if(cnt != -1)
    printf("Billboardu: %d\n",cnt);
    else
    printf("N/A\n");
  }


  return 0;
}