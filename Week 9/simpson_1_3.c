#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double integration_simpson_1_3(int n, double h, double f[n])
{
    double sim=0;
    int i;

    for (i=0;i<=n;i++)
    {   
        if (i==0 || i==(n))
        {
            sim += h/3*f[i]*f[i];
        }
        else if(i%2 == 0 && i != (n))
        {
            sim += 2*h/3*f[i]*f[i];
        }
        else
        {
            sim += 4*h/3*f[i]*f[i];
        }
         //printf("%d %lf\n",i, sim);
    }

    return sim;
}