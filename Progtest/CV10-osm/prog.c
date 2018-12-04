#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int searchRow(int * arr, int * checked, int w, int size, int * word, int wordSize){

  for (int i = 0; i < size; i++)  
  {
    printf("%c",(char)arr[i]); 
    if((i+1) % w == 0 && i != 0){
      printf("\n");
    } 
  }
}

int main (void){
  int * checked = (int *)malloc(1 * sizeof(int));
  int * arr = (int *)malloc(1 * sizeof(int));
  int * used = (int *)malloc(1 * sizeof(int));
  int usedSize = 0;
  int w = 0;
  int size = 0;
  char c = ' ';
  int series = 0;
  int row = 0;
  while(1){
    int skip = 0;
    scanf("%c",&c);  
    if((c == '\n') && series == 1){
      break;
    }
    series = 0;
    if(c == '\n' && w == 0){
      w = size;
      skip = 1;
    }

    
    if(c == '\n'){
      row++; 
      if(w*row != size){
        return 0;
      }   
      series = 1;
    }
    else{
      int * tmp = (int *)malloc((size+1) * sizeof(int));
      int * tmp2 = (int *)malloc((size+1) * sizeof(int));
      for (int i = 0; i < size; i++){ 
        tmp[i] = arr[i];
        tmp2[i] = checked[i];
      }
      free(arr);
      free(checked);
      arr = tmp;  
      checked = tmp2;

      arr[size] = (int)c;
      
      if(c != '.'){
        checked[size] = 0;
      }
      else
        checked[size] = 1;


      size++;
      int is = 0;
      for(int i = 0; i < usedSize; i++){
        if(used[i] == (int)c)
          is = 1;
      }
      if(is == 0){
        int * tmpUsed = (int *)malloc((usedSize+1) * sizeof(int));
        for (int i = 0; i < usedSize; i++) 
          tmpUsed[i] = used[i];
        free(used);

        used = tmpUsed;
        used[usedSize] = (int)c;
        usedSize++;

      }
    }
  }
  for (int i = 0; i < size; i++)  
  {
    printf("%c",(char)arr[i]); 
    if((i+1) % w == 0 && i != 0){
      printf("\n");
    } 
  }
  for (int i = 0; i < size; i++)  
  {
    printf("%d",checked[i]); 
    if((i+1) % w == 0 && i != 0){
      printf("\n");
    } 
  }

  printf("\n Pismena: ");
  for (int i = 0; i < usedSize; i++)  
    printf("%c",(char)used[i]); 
  printf("\n%d",w);
  char word[100];
  scanf("%s", word);
  printf("\n%s\n", word);
  return 0;
}