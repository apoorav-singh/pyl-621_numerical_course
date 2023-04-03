// PH621 - EndSem Lab
// Code By:
// Apoorav Singh Deo
// Roll No: v19036

#include<stdio.h>
#include<math.h>

// Analytical Results for the comparison of the reuslt

double analytic(double t)
{
    double x_t;

    double a = 1; //Acceleration 

    double x_0 = 250, v_0 = 25; // Initial values

    x_t = x_0 + v_0*t + 0.5*a*pow(t,2);

    return x_t; 
}

// This given function will solve second order diffrential equation.

// "y0" is initial value for y
// "z0" is initial value for dx/dt = v (Velocity)
// "x0" is initial value for t (time)
// "grid" is the number data points we are including
// "h" is the step value

double RK_4(double y0, double z0, double x0, int grid, double h)
{
    double a = 1; //Acceleration

    double x[grid], y[grid], z[grid];

    double k11, k21, k31, k41, k12, k22, k32, k42;

    int i;

    z[0] = z0;
    y[0] = y0;


    FILE *fp = fopen("RK4.dat", "w");

   fprintf(fp, "Time(t)\t Analytic\t RK-4 \n");

    for (i=0;i<=grid;i++)
    {
        x[i] = x0 + i*h;

        k11 = z[i];

        k12 = a;
        
        k21 = (z[i]+k12*h/2);
        
        k22 = a;
        
        k31 = (z[i]+k22*h/2);
        
        k32 = a;
        
        k41 = (z[i]+k32*h);
        
        k42 = a;

        y[i+1] = y[i] + h/6*(k11+2*k21+2*k31+k41);
        z[i+1] = z[i] + h/6*(k12+2*k22+2*k32+k42);

        fprintf(fp, "%lf\t %lf\t %lf\n", x[i], analytic(x[i]), y[i]);
        //printf("Velocity (kmph) at time %lf seconds: %lf\n",x[i], z[i]*(3.6));
    }

    fclose(fp);
    printf("Velocity (kmph) at time %lf seconds: %lf\n",x[grid], z[grid]*(3.6));
    printf("Distance Travelled (km) during acceleration period: %lf km\n", (y[grid]-y[0])*(0.001));
    

    
}

void main()
{
    // As car is moving in constant acceleration for 1 minute

    double t_in = 0, t_fin = 60;

    double h;
    printf("Enter the step value: ");
    scanf("%lf", &h);
    

    int grid = (t_fin - t_in)/h;

    double x0 = 250, v0 = 25;

    // Calling the function 

    RK_4(x0, v0, t_in, grid, h);

}
