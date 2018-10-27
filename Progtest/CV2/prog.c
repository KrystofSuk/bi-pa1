#include <stdio.h>
#include <math.h>

#define DBL_EPSILON 2.2204460492503131e-16 
#define M_PI 3.14159265358979323846

int CompatibilityTriangle(double Lenghts[3]);
int SameTriangle(double LenghtsA[3], double LenghtsB[3]);
int main(void){
    double First [6];
    double Second [6];
    printf("Trojuhelnik #%d:\n", 1);
    printf("Bod A:\n");
    if(scanf("%lf %lf", &First[0], &First[1])!=2){
        printf("Nespravny vstup.\n");
        return 0;   
    }
    printf("Bod B:\n");
    if(scanf("%lf %lf", &First[2], &First[3])!=2){
        printf("Nespravny vstup.\n"); 
        return 0;  
    }
    printf("Bod C:\n");
    if(scanf("%lf %lf", &First[4], &First[5])!=2){
        printf("Nespravny vstup.\n"); 
        return 0;  
    }

    /*Converting to lenghts*/
    double LenghtsF[3];
    LenghtsF[0]= sqrt( pow(First[0]-First[2],2)+pow(First[1]-First[3],2));
    LenghtsF[1]= sqrt( pow(First[2]-First[4],2)+pow(First[3]-First[5],2));
    LenghtsF[2]= sqrt( pow(First[4]-First[0],2)+pow(First[5]-First[1],2));
    /*Check for compatible triangle*/
    if(CompatibilityTriangle(LenghtsF) != 1){
        printf("Body netvori trojuhelnik.\n");
        return 0;
    }

    printf("Trojuhelnik #%d:\n", 2);
    printf("Bod A:\n");
    if(scanf("%lf %lf", &Second[0], &Second[1])!=2){
        printf("Nespravny vstup.\n"); 
        return 0;  
    }
    printf("Bod B:\n");
    if(scanf("%lf %lf", &Second[2], &Second[3])!=2){
        printf("Nespravny vstup.\n");  
        return 0; 
    }
    printf("Bod C:\n");
    if(scanf("%lf %lf", &Second[4], &Second[5])!=2){
        printf("Nespravny vstup.\n");  
        return 0; 
    }

    

    double LenghtsS[3];
    LenghtsS[0]= sqrt(pow(Second[0]-Second[2],2)+pow(Second[1]-Second[3],2));
    LenghtsS[1]= sqrt(pow(Second[2]-Second[4],2)+pow(Second[3]-Second[5],2));
    LenghtsS[2]= sqrt(pow(Second[4]-Second[0],2)+pow(Second[5]-Second[1],2));

    
    if(CompatibilityTriangle(LenghtsS) != 1){
        printf("Body netvori trojuhelnik.\n");
        return 0;
    }

    int t = SameTriangle(LenghtsF, LenghtsS);
    if(t == 1 ){
        printf("Trojuhelniky jsou shodne.\n");
    }
    else{
        double o1 = LenghtsF[0] + LenghtsF[1] + LenghtsF[2];
        double o2 = LenghtsS[0] + LenghtsS[1] + LenghtsS[2];
            //printf("%f %f %.20f, %.20f\n", o1 ,o2, o1-o2, 1000*DBL_EPSILON*o2);
        if(o1 - o2 > 1000*DBL_EPSILON*o2){
            printf("Trojuhelnik #1 ma vetsi obvod.\n");
        }else if(o1 - o2 < 1000*DBL_EPSILON*-o2){
            printf("Trojuhelnik #2 ma vetsi obvod.\n");
        }else{
            printf("Trojuhelniky nejsou shodne, ale maji stejny obvod.\n");
        }
    }
    

    
    return 0;
}

int CompatibilityTriangle(double Lenghts[3]){

    int a =0;
    int b =0;
    int c =0;
    if(Lenghts[0] < Lenghts[1] && Lenghts[0] < Lenghts[2]){
        a = 0;
    }else if(Lenghts[1] < Lenghts[0] && Lenghts[1] < Lenghts[2]){
        a = 1;
    }else{
        a = 2;
    }
    if(Lenghts[0] > Lenghts[1] && Lenghts[0] > Lenghts[2]){
        c = 0;
    }else if(Lenghts[1] > Lenghts[0] && Lenghts[1] > Lenghts[2]){
        c = 1;
    }else{
        c = 2;
    }
    if(a == 0 && c==1){
        b = 0;
    }
    if(a == 0 && c==2){
        b = 1;
    }
    if(a == 1 && c==0){
        b = 2;
    }
    if(a == 1 && c==2){
        b = 0;
    }
    if(a == 2 && c==0){
        b = 1;
    }
    if(a == 2 && c==1){
        b = 0;
    }
    double sum = Lenghts[a]+Lenghts[b]-Lenghts[c];
    if(sum> 1000*DBL_EPSILON*Lenghts[c]){
        return 1;
    }
    return 0;
}

int SameTriangle(double LenghtsA[3], double LenghtsB[3]){
    double angleA1;
    double angleB1;
    double angleC1;
    double angleA2;
    double angleB2;
    double angleC2;
    angleC1 = cos((pow(LenghtsA[0],2)+pow(LenghtsA[1],2)-pow(LenghtsA[2],2))/(2*LenghtsA[0]*LenghtsA[1]));
    angleA1 = cos((-pow(LenghtsA[0],2)+pow(LenghtsA[1],2)+pow(LenghtsA[2],2))/(2*LenghtsA[1]*LenghtsA[2]));
    angleB1 = cos((pow(LenghtsA[0],2)-pow(LenghtsA[1],2)+pow(LenghtsA[2],2))/(2*LenghtsA[0]*LenghtsA[2]));
    angleC2 = cos((pow(LenghtsB[0],2)+pow(LenghtsB[1],2)-pow(LenghtsB[2],2))/(2*LenghtsB[0]*LenghtsB[1]));
    angleA2 = cos((-pow(LenghtsB[0],2)+pow(LenghtsB[1],2)+pow(LenghtsB[2],2))/(2*LenghtsB[1]*LenghtsB[2]));
    angleB2 = cos((pow(LenghtsB[0],2)-pow(LenghtsB[1],2)+pow(LenghtsB[2],2))/(2*LenghtsB[0]*LenghtsB[2]));
    /*
    printf("%f\n", angleA1*180/M_PI);
    printf("%f\n", angleB1*180/M_PI);
    printf("%f\n", angleC1*180/M_PI);
    printf("%f\n", angleA2*180/M_PI);
    printf("%f\n", angleB2*180/M_PI);
    printf("%f\n", angleC2*180/M_PI);
    */
    int count = 0;
    if(angleA1 == angleA2 && angleA1 != 0 && angleA2 != 0){
        count++;
        angleA1 = 0;
        angleA2 = 0;
    }else if(angleA1 == angleB2 && angleA1 != 0 && angleB2 != 0){
        count++;
        angleA1 = 0;
        angleB2 = 0;
    }else if(angleA1 == angleC2 && angleA1 != 0 && angleC2 != 0){
        count++;
        angleA1 = 0;
        angleC2 = 0;
    }else if(angleB1 == angleA2 && angleB1 != 0 && angleA2 != 0){
        count++;
        angleB1 = 0;
        angleA2 = 0;
    }else if(angleB1 == angleB2 && angleB1 != 0 && angleB2 != 0){
        count++;
        angleB1 = 0;
        angleB2 = 0;
    }else if(angleB1 == angleC2 && angleB1 != 0 && angleC2 != 0){
        count++;
        angleB1 = 0;
        angleC2 = 0;
    }else if(angleC1 == angleA2 && angleC1 != 0 && angleA2 != 0){
        count++;
        angleC1 = 0;
        angleA2 = 0;
    }else if(angleC1 == angleB2 && angleC1 != 0 && angleB2 != 0){
        count++;
        angleC1 = 0;
        angleB2 = 0;
    }else if(angleC1 == angleC2 && angleC1 != 0 && angleC2 != 0){
        count++;
        angleC1 = 0;
        angleC2 = 0;
    }else{
        return 0;
    }
    if(angleA1 == angleA2 && angleA1 != 0 && angleA2 != 0){
        count++;
        angleA1 = 0;
        angleA2 = 0;
    }else if(angleA1 == angleB2 && angleA1 != 0 && angleB2 != 0){
        count++;
        angleA1 = 0;
        angleB2 = 0;
    }else if(angleA1 == angleC2 && angleA1 != 0 && angleC2 != 0){
        count++;
        angleA1 = 0;
        angleC2 = 0;
    }else if(angleB1 == angleA2 && angleB1 != 0 && angleA2 != 0){
        count++;
        angleB1 = 0;
        angleA2 = 0;
    }else if(angleB1 == angleB2 && angleB1 != 0 && angleB2 != 0){
        count++;
        angleB1 = 0;
        angleB2 = 0;
    }else if(angleB1 == angleC2 && angleB1 != 0 && angleC2 != 0){
        count++;
        angleB1 = 0;
        angleC2 = 0;
    }else if(angleC1 == angleA2 && angleC1 != 0 && angleA2 != 0){
        count++;
        angleC1 = 0;
        angleA2 = 0;
    }else if(angleC1 == angleB2 && angleC1 != 0 && angleB2 != 0){
        count++;
        angleC1 = 0;
        angleB2 = 0;
    }else if(angleC1 == angleC2 && angleC1 != 0 && angleC2 != 0){
        count++;
        angleC1 = 0;
        angleC2 = 0;
    }else{
        return 0;
    }
    if(count == 2){
        return 1;
    }else{
        return 0;
    }
}