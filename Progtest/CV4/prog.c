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
        //printf("%lld/", res);
    }
        //printf("\n");
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

long long int numberOfCombinations(long long int lo, long long int hi){
    
    int base = numberOfDigits(lo)-1;
    
    long long int combInBase = pow(2, base);
    long long int l =lo;
    for(int i = 0; i <= numberOfDigits(lo)-2; i++){
        
        long long int t = l%10;
        l/=10;
        if(t == 1){
            long long int tmp = pow(2,i);
            combInBase -= pow(2,i);
        }
        
    }
    if(lo == 0){
        combInBase += 2;
    }

    base = numberOfDigits(hi)-1;
    
    long long int tempCombInBase = pow(2, base);
    long long int h = hi;
    for(int i = 0; i <= numberOfDigits(hi)-2; i++){
        
        long long int t = h%10;
        h/=10;
        if(t == 1){
            long long int tmp = pow(2,i);
            tempCombInBase -= pow(2,i);
        }
        
    }
    if(hi == 0){
        tempCombInBase += 2;
    }
    tempCombInBase=pow(2,base)-tempCombInBase+1;
    long long int maxComp = pow(2,base)- tempCombInBase;
    if(numberOfDigits(lo) == numberOfDigits(hi)){
        long long int total =0;
        total += (combInBase-maxComp) * numberOfDigits(lo);
        return total;
    }
    //printf("M: %lld\n", maxComp);
    long long int total =0;
    total += combInBase * numberOfDigits(lo);

    for(int i = numberOfDigits(lo)+1; i < numberOfDigits(hi); i++){
        
        total += pow(2,i-1)*i;
    }
    
    total += tempCombInBase * numberOfDigits(hi);
    if(lo == 0){
        total+=1;
    }
    return total;
}

void calculateNumbers(long long int lo, long long int hi){
    long long int res = 0;
    printf("Cifer: %lld\n", numberOfCombinations(lo, hi));
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
        calculateNumbers(convertToBase(lo,2),convertToBase(hi,2));
    }
    else if(op == 'z'){

    }
    else if(op == 's'){

    }
    return 0;
}