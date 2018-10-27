#include <stdio.h>
#include <math.h>

int main(void){
    
    double ang = 0;
    double fill = 100;
    printf("What is the angle: ");
    if(scanf("%lf", &ang)!=1){
        printf("Bad input!\n");
        return 1;
    }
    if(ang < 0){
        ang *= -1;
    }

    double A [2] ={0,0};
    double C [2] ={1,1};
    double D [2] ={0,1};

    double distance = sqrt(2)/2;
    ang+=45;
    double ang2 = ang-45;
    ang = ang*3.14159265358979323846/180;
    C[0] = sin(ang)/distance;
    C[1] = cos(ang)/distance;
    A[0] = sin(ang)/-distance;
    A[1] = cos(ang)/-distance;
    D[0] = -cos(ang)/distance;
    D[1] = sin(ang)/distance;
    double tmp = (A[0]+tan(ang2*3.14159265358979323846/180)*A[1]);
    if(tmp > 0){
        tmp *= -1;
    }
    double T [2] ={tmp,0};

    printf("A: %f %f \n", A[0], A[1]);
    printf("C: %f %f \n", C[0], C[1]);
    printf("D: %f %f \n", D[0], D[1]);
    printf("T: %f %f \n", T[0], T[1]);

    double TC = sqrt((T[0]-C[0])*(T[0]-C[0])+(T[1]-C[1])*(T[1]-C[1]));
    double TD = sqrt((T[0]-D[0])*(T[0]-D[0])+(T[1]-D[1])*(T[1]-D[1]));
    double DC = sqrt((D[0]-C[0])*(D[0]-C[0])+(D[1]-C[1])*(D[1]-C[1]));
    double s = (TC+TD+DC)/2;
    double S1 = sqrt(s*(s-TC)*(s-TD)*(s-DC));

    double S = (S1)/2*100;

    printf("TC TD DC: %f %f %f \n", TC, TD, DC);
    printf("S1 DC: %f %f \n", S1, S);

    

    printf("For angle %f cube stays filled at %f", ang, S);
    return 0;
}