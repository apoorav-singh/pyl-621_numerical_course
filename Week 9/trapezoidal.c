#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double integration_trapezoidal(int n, double h, double f[n])
{
    double trap=0;
    int i;

    for (i=0;i<=n;i++)
    {
        if (i==0 || i==(n))
        {
            trap += (h/2)*f[i]*f[i];
        }
        else
        {
            trap += h*f[i]*f[i];
        }
        
        //printf("%d %lf\n",i, trap);
    }

    return trap;
}