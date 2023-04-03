#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#include "trapezoidal.c"
#include "simpson_1_3.c"

// Function to be Integrated

// !pow(float/int, int/float (don't give fractions as 1/4))

double phi(double x)
{
    double ph, e, C;
    e = 0.25;
    C = 1/M_PI;
    ph = pow(C,e)*sqrt(2)*x*exp(-pow(x,2)/2);
    return ph;
    //return pow((1/(double)M_PI),(1/4))*sqrt(2)*x*exp(-pow(x,2)/2);
}



int main()
{   
    int j;
    double A_1 = 1.0;
    printf("Absoulute value of the A_1 = %lf\n", A_1);
    printf("\n");
    printf(" h    Trapezoidal    Error     Simpson(1/3)   Error\n");
    while(j<3)
    {
    double h[3]={0.5,0.2,0.1};
    
    // printf("Enter the value of h: ");
    // scanf("%lf", &h);

    double end_v = 3, start_v=-3;
    int n=(end_v-start_v)/h[j];
    
    double x[n], f[n];

    FILE *fp1 = fopen("test.dat", "w");

    for (int i=0;i<=n;i++)
    {
        x[i] = start_v + i*h[j];
        f[i] = phi(x[i]);
        fprintf(fp1, "%lf %lf\n", x[i], f[i]);
    }

    fclose(fp1);

    // Area under the curve using trapezoidal rule

    double err_1, err_2;

    

    printf("%0.2lf   ", h[j]);

    double trap = integration_trapezoidal(n, h[j], f);
    printf("%lf    ", 1/sqrt(trap));

    err_1 = fabs((1/sqrt(trap))-A_1)/A_1*100;

    printf("%lf%%   ", err_1);

    double sim = integration_simpson_1_3(n, h[j], f);

    printf("%lf    ", 1/sqrt(sim));

    err_2 = fabs((1/sqrt(sim))-A_1)/A_1*100;

    printf("%lf%% \n", err_2);

    j++;

}

}