#include<stdio.h>
#include<math.h>



double analytic(double t)
{
    double alp = 0.001; // constant of propotionality
    double T_t;
    double A_s = 4*M_PI; // km^2
    double C = 1340.0;
    double T_f = 10.0;

    T_t = C*exp(-alp*A_s*t) + T_f;

    return T_t; 
}

double RK_4(double T_0, double h)
{
    // propotionality constant is plugged to one
    double A_s = 4*M_PI; // km^2
    double alp = 0.001;
    double T_f = 10.0;
    double k_1 = -alp*A_s*(T_0 - T_f);
    double k_2 = -alp*A_s*((T_0+k_1*h/2) - T_f);
    double k_3 = -alp*A_s*((T_0+k_2*h/2) - T_f);
    double k_4 = -alp*A_s*((T_0+k_3*h) - T_f);
    double T_1;

    T_1 = T_0 + h/6*(k_1+2*k_2+2*k_3+k_4);
    
    return T_1;
}


void main()
{

    double h;
    printf("Enter the step value: ");
    scanf("%lf", &h);

    int grid = 1000;
    double t[grid], T[grid]; // time is in seconds, and Temprature in degree *C
    int i;

    double toler_0;

    FILE *fp0 = fopen("analytical.txt","w");

    for (i=0;i<grid;i++)
    {   
        t[i] = i*h;
        
        toler_0 = fabs(10.0-analytic(t[i]))/10.0*100.0;
        
        if (toler_0 <= 0.01)
        {
            printf("In %lf (s) asteroid will cool down to sea temprature (according to Analytic Function)\n", t[i]);
            break;
        }
        fprintf(fp0, "%lf %lf\n",t[i], analytic(t[i]));
    }

    fclose(fp0);

    FILE *fp1 = fopen("RK_4.txt", "w");

    T[0] = 1350.0;

    double toler;

    fprintf(fp1, "%lf %lf\n", t[0], T[0]);

    for (i=1;i<grid;i++)
    {
        T[i] = RK_4(T[i-1], h);

        toler = fabs(10.0-T[i])/10.0*100.0;
        
        if (toler <= 0.01)
        {
            printf("In %lf (s) asteroid will cool down to sea temprature (according to RK-4 Solution)\n", t[i]);
            break;
        }
        
        fprintf(fp1, "%lf %lf\n", t[i], T[i]);


    }

    fclose(fp1);
}