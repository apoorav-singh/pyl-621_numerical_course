#include<stdio.h>
#include<math.h>

// Analytical Results for the comparison of the reuslt

double analytic(double x)
{
    double C = pow(1/M_PI,0.25);
    double psi_ana;

    psi_ana = C*exp(-0.5*x*x) ;

    return psi_ana; 
}

// This given function will solve second order diffrential equation.

// "y0" is initial value for y
// "z0" is initial value for dy/dx = z
// "x0" is initial value for x (position)
// "grid" is the number data points we are including
// "h" is the step value

double RK_4(double y0, double z0, double x0, int grid, double h)
{
    double x[grid], y[grid], z[grid];

    double k11, k21, k31, k41, k12, k22, k32, k42;

    int i;

    z[0] = z0;
    y[0] = y0;

    FILE *fp = fopen("QHO.txt", "w");

    for (i=0;i<grid;i++)
    {
        x[i] = x0 + i*h;

        k11 = z[i];

        k12 = (pow(x[i],2) - 1)*y[i];
        
        k21 = (z[i]+k12*h/2);
        
        k22 = (pow((x[i]+h/2),2) - 1)*(y[i] + k11*h/2);
        
        k31 = (z[i]+k22*h/2);
        
        k32 = (pow((x[i]+h/2),2) - 1)*(y[i] + k21*h/2);
        
        k41 = (z[i]+k32*h);
        
        k42 = (pow((x[i]+h),2) - 1)*(y[i] + k31*h);

        y[i+1] = y[i] + h/6*(k11+2*k21+2*k31+k41);
        z[i+1] = z[i] + h/6*(k12+2*k22+2*k32+k42);

        fprintf(fp, "%lf    %lf    %lf\n", x[i], analytic(x[i]), y[i]);
    }

    fclose(fp);
}

void main()
{
    double x_in = -2.5, x_fin = 2.5;

    double h;
    printf("Enter the step value: ");
    scanf("%lf", &h);
    

    int grid = (x_fin - x_in)/h;

    double y0 = 0.0330, z0 = 0.08250;

    // Calling the function 

    RK_4(y0, z0, x_in, grid, h);

}

/* As it is evident that as we decrease the value of h we get more accurate results from RK-4 method. */