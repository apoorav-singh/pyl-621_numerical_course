// Built by: Apoorav Singh Deo
// Roll No: v19036

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "line_counting.c"

double trajec(double x, double theta, double in_vel)
{
    double g=(pow(3600,2)/1000)*9.81;
    double ht;


    ht = tan(theta)*x - (g/(2*pow(in_vel,2)*pow(cos(theta),2))*pow(x,2));
    return ht;
}
void main()
{
    printf("\n-------------Lagrange's Interpolation-------------\n");
    int i,j;
    char file_name[200];
    printf("\nEnter the file name: ");
    scanf("%s", *&file_name);
    // Array Size 
    int n = read_file_line(file_name);
    int N=6;
    // Input Values
    double pos[N], h[N];
    //double PI = 4*atan(1);

    // Taking input from the file
    FILE *fp=fopen(file_name,"r");
    for (i=0;i<n;i++)
    {
        fscanf(fp, "%lf %lf", &pos[i], &h[i]);
        //printf("%lf %lf\n", pos[i], h[i]);
    }
    fclose(fp);

    double x_in, fn=0, L[N];
    printf("\nEnter the argument of the function: ");
    scanf("%lf", &x_in); 
    printf("\n-----------------------------------------------------------\n");

    for (i=0;i<n;i++)
    {
        L[i] = 1;
        for (j=0;j<n;j++)
        {
            if(i == j)
            {   
                L[i] *= 1;
                continue;
            }
            else
            {
                L[i] *= ((x_in-pos[j])/(pos[i]-pos[j])); 
                printf("At %d iteration, L[%d] = %lf\n", j+1, i+1, L[i]);
            }

        }
        printf("-----------------------------------------------------------\n");
        fn += L[i]*h[i];
    }
    printf("\nF(%0.2lf) = %lf\n", x_in, fn);

    // Value from the analytical result

    double ana_h;

    ana_h = trajec(x_in, M_PI/6, 2815.58);

    printf("\nAnalytical Result: %lf\n", ana_h);

    double rel_err = fabs(ana_h - fn)/ana_h*100;

    printf("\nRelative Error = %lf%%\n", rel_err);


    printf("\nNumber of lines in the file are: %d\n", n);


}