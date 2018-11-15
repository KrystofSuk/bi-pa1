#include <stdio.h>
#include <math.h>

void errorLog(){
    printf("Nespravny vstup.\n");
    return;
}

int convertToBase(char* resChar, int number, int base){
    int num = number;
    int index = 0;
    if(num == 0){
        resChar[0] = '0';
    }
    char tmpAR [30] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    while(num > 0){
        int tmp = num % base;
        num-=tmp;
        num/=base;
        int i = 0;
        if(tmp+48 <= 57 && tmp+48 >= 48){
            i = 48;
        }else if(tmp+55 <= 90 && tmp+55 >= 65){
            i=55;
        }
        tmpAR[index] = tmp + i;
        //printf("T: %c\n", (int)(resChar[index]));
        index++;
    }
    int it = 0;
    for(int i = 29; i >= 0; i--){
        if(tmpAR[i] != ' '){
            resChar[it] = tmpAR[i];
            it++;
        }
    }
    return 0;
}

int numberOfDigits(char num[] ){
    int res = 0;
    for(int i = 0; i < 30; i++){
        if(num[i] != ' '){
            //printf("%c",num[i]);
            res++;
        }else{
            return res;
        }
        
    }
    return res;
}
int numberOfNulls(char num[]){
    int res = 0;    
    for(int i = 0; i < 30; i++){
        if(num[i] == '0'){
            res++;
        }        
    }
    return res;
}
int numberOfNullsSequence(char num[]){
    int maxRes = 0;
    int res = 0;
    for(int i = 0; i < 30; i++){
        if(num[i] == '0'){
            res ++;
            if(res > maxRes)
                maxRes = res;
        }else{
            res = 0;
        }
    }
    return maxRes;
}
void calculateNumbers(int lo, int hi, int base, char result[]){
    int res = 0;
    int num = lo;
    while(num <= hi){
        for(int i = 0; i < 30; i++){
            result[i] = ' ';
        }
        convertToBase(result, num, base);
        //printf("/");
        res += numberOfDigits(result);
        num+=1;
    }
    if(lo == 0){
        //res += 1;
    }
    printf("Cifer: %d\n", res);
}
void calculateNulls(int lo, int hi, int base, char result[]){
    int res = 0;
    int num = lo;
    while(num <= hi){
        for(int i = 0; i < 30; i++){
            result[i] = ' ';
        }
        convertToBase(result,num, base);
        //printf("%c,",result[0]);
        res += numberOfNulls(result);
        num+=1;
    }
    if(lo == 0){
        //res += 1;
    }
    printf("Nul: %d\n", res);
}
void calculateSequence(int lo, int hi, int base, char result[]){
    int res = 0;
    int num = lo;
    while(num <= hi){
        for(int i = 0; i < 30; i++){
            result[i] = ' ';
        }
        convertToBase(result, num, base);
        int t = numberOfNullsSequence(result);
        if(res < t){
            res = t;
        }
        num+=1;
    }
    printf("Sekvence: %d\n", res);
}
int main(void){
    printf("Zadejte intervaly:\n");
    int lo = 0;
    int hi = 0;
    char op;
    int flag = 0;
    int base = 10;
    char result [30] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
    while(flag ==0)
    {
        if(scanf(" r %d", &base)!=1){
            base = 10;
            
            if(scanf(" < %d ; %d > %c", &lo, &hi, &op) == 3){
                if(lo < 0 || hi < 0 || lo > hi || (op != 'l' && op != 'z' && op != 's')){
                    errorLog();
                    return 0;    
                }
                if(op == 'l'){
                    calculateNumbers(lo,hi,base,result);
                }
                else if(op == 'z'){
                    calculateNulls(lo,hi,base,result);
                }
                else if(op == 's'){
                    calculateSequence(lo,hi,base,result);
                }
            }else{
                flag = 1;
                if(feof(stdin)==0)
                    errorLog();              
            }
        }else{            
            if(base < 2 || base > 36){
                errorLog();
                    return 0;  
            }
            
            if(scanf(" : < %d ; %d > %c", &lo, &hi, &op) == 3){
                if(lo < 0 || hi < 0 || lo > hi || (op != 'l' && op != 'z' && op != 's')){
                    errorLog();
                    return 0;    
                }
                if(op == 'l'){
                    calculateNumbers(lo,hi,base,result);
                }
                else if(op == 'z'){
                    calculateNulls(lo,hi,base,result);
                }
                else if(op == 's'){
                    calculateSequence(lo,hi,base,result);
                }
            }else{
                flag = 1;
                if(feof(stdin)==0)
                    errorLog();              
            }
        }
    }
    return 0;
}