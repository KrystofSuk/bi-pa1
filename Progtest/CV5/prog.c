#include <stdio.h>
#include <math.h>

void errorLog(){
    printf("Nespravny vstup.\n");
    return;
}

long long int convertToBase(long long int number, int base){
    long long int num = number;
    long long int index = 0;
    long long int res = 0;
    while(num > 0){
        int tmp = num % base;
        num-=tmp;
        num/=base;
        double pw = pow(10,index);
        res += tmp * (long long int)pw;
        index++;
    }
    return res;
}

int numberOfDigits(long long int num){
    if(num <= 0){
        return 0;
    }
    int res = (int)(floor(log10(num))+1);
    if(res > 15){
        res-=1;
    }
    return res;
}

int numberOfNulls(long long int num){
    int res = 0;
    if(num <= 0){
        return 1;
    }
    long long int t = num;
    
    for(int i = numberOfDigits(num); i > 0; i--){
        
        long long int tmp = (t%10);
        if(tmp == 0){
            res ++;
        }
        t/=10;
    }
    return res;
}

int numberOfNullsSequence(long long int num){
    int res = 1;
    if(num <= 0){
        return 1;
    }
    long long int t = num;
    int maxRes = 1;
    for(int i = numberOfDigits(num); i > 0; i--){
        
        long long int tmp = (t%10);
        if(tmp == 0){
            res ++;
            if(res > maxRes){
                maxRes = res;
            }
        }
        if(tmp == 1){
            res = 0;
        }
        t/=10;
    }
    return maxRes;
}

void calculateNumbers(long long int lo, long long int hi, int base){
    long long int res = 0;
    long long int num = lo;
    while(num <= hi){
        res += numberOfDigits(convertToBase(num, 2));
        num+=1;
    }
    if(lo == 0){
        res += 1;
    }
    printf("Cifer: %lld\n", res);
}

void calculateNulls(long long int lo, long long int hi, int base){
    long long int res = 0;
    long long int num = lo;
    while(num <= hi){
        res += numberOfNulls(convertToBase(num, 2));;
        num+=1;
    }
    if(lo == 0){
        //res += 1;
    }
    printf("Nul: %lld\n", res);
}

void calculateSequence(long long int lo, long long int hi, int base){
    long long int res = 0;
    long long int num = lo;
    while(num <= hi){
        int t = numberOfNullsSequence(convertToBase(num, 2));
        if(res < t){
            res = t;
        }
        num+=1;
    }
    printf("Sekvence: %lld\n", res-1);
}

int main(void){
    printf("Zadejte interval:\n");
    int lo = 0;
    int hi = 0;
    char op;
    if(scanf(" < %d ; %d > %c", &lo, &hi, &op) != 3){
        errorLog();
        return 0;
    }
    if(lo < 0 || hi < 0 || lo > hi || (op != 'l' && op != 'z' && op != 's')){
        errorLog();
        return 0;    
    }
    if(op == 'l'){
        calculateNumbers(lo,hi,2);
    }
    else if(op == 'z'){
        calculateNulls(lo,hi,2);
    }
    else if(op == 's'){
        calculateSequence(lo,hi,2);
    }
    return 0;
}