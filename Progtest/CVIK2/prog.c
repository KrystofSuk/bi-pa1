#include <stdio.h>
#include <math.h>

void print(char* txt){
    printf("%s", txt);
}
int printRet(char* txt){
    printf("%s", txt);
    return 5;
}

int printRectangle(int x, int y, int h, int w){
    
    int t = 0;
    t = (y >= w)?1: 0;
    if(t == 1){
        return 0;
    }
    int sideA = 0;
    int sideB = 0;
    sideA = (y == 0||y==h-1) ? 1 : 0;
    sideB = (x == 1||x==w) ? 1 : 0;
    int res = 0;
    res = (sideA == 1 && sideB == 0)?1:0;
    res = (res == 0 && ( sideA == 0 && sideB == 1))?2:res;
    res = (res == 0 && (sideA == 1 && sideB == 1))?3:res;
    int tmp = 0;
    tmp = (res == 0) ? printRet("*"):0;
    tmp = (res == 1) ? printRet("-"):0;
    tmp = (res == 2) ? printRet("|"):0;
    tmp = (res == 3) ? printRet("x"):0;
    
    t = (t==0 && x >= w)?printRet("\n") * printRectangle(1, y+1,h,w):printRectangle(x+1, y,h,w);
    return 1;
}

int main(void){
    int h = 0;
    int w = 0;
    print("Input\nh: ");
    int tmp=0;
    tmp = scanf("%d", &h);
    h = (tmp == 0 || h < 3) ? printRet("Bad input setting h to 5 \n"):h;
    w = (tmp == 0) ? 5:0;
    print("w: ");
    tmp = scanf("%d", &w);
    w = (tmp == 0 || w < 3) ? printRet("Bad input setting h to 5 \n"):w;
    print("\n");

    printRectangle(1,0, h ,w);

    return 0;
}