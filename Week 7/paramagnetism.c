// Code By: Apoorav Singh Deo
// Roll No: v19036

// Driver code

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include "line_counting.c" // Counts number of data points
#include "newton_interpolation.c" // Code for the Newton forward interpoltion


double ana_func(double x)
{
    double N = 1.0, mu = 1.0, f;

    f = N*mu*((1/tanh(x))-(1/x));


    return f;

}

int main()
{
    int i, n;
    
    // n is the number of data points.
    n = read_file_line("nfi_input.dat");

    double x[n], M[n], x_arg = 2.0, ana;

    // Reading data from the source file 
    FILE *fp = fopen("nfi_input.dat", "r");

    for (i=0;i<n;i++)
    {
        fscanf(fp,"%lf %lf", &x[i], &M[i]);
        // printf("%lf %lf\n", x[i], M[i]);
    }

    // Analytical Function Check

    printf("M(%lf) = %lf \n", x_arg, ana = ana_func(x_arg));

    // Newton's Forward differnce Method

    newton_forward(n, x_arg, x, M, ana);

}