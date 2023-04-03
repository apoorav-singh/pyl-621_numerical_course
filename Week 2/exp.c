
// To estimate the value of the exponential function using Taylor Series expansion.
// To find the error in each iteration.
// Later using that function find the number of atoms after radioactive deacy.

#include<stdio.h>
#include<math.h>

long int fac(int n1)
{
    long int N2=1;
    if (n1==0)
    {
        return N2;
    }
    else
    {k
        for(int i=1;i<=n1;i++)
        {
            N2=N2*i;
        }
    return N2;
    }    
}

double tay_exp(double t1, int* j1,double* ER)
{
    double  N1=0.0,err,N2=0.0,f,err_ab, Ab_v;
    int i,j=1;
    for(i=0;i<=j;i++)
    {   
        f = fac(i);
        N1 += pow(t1,i)/f;
        err = ((N2-N1)/N1)*100; // Relative error on the iteration
        Ab_v = exp(t1); // True Value
        err_ab = (Ab_v-N1); // Absoulte Error
        printf("Iteration number: %d | Relative Error : %07.2lf%% | Absolute Error: %lf | Computed Value: %lf\n", i+1,fabs(err),fabs(err_ab), N1);
        N2=N1;
        j=j+1;
        
        // fabs() to mod the value.
        
        if(fabs(err) <= 0.001)
        {
            break;
        }

    }
    printf("-------------------------------------------------------------------\n");
    printf("Actual Value: %lf \n", Ab_v);
    *j1=i;
    *ER=err;
    return N1;
}


void main()
{
    int i,i1=20,k;
    long double  m=2.0,m_m=237.0487,N[i1],t[i1],t_h=6.75,err,lamb,N_o,N_a=6.023e23;
    double err_f;
    N_o=N_a*(m/m_m);
    lamb = -0.693/t_h;
    t[0] = 4.869;

    //for(i=0;i<i1;i++)
    //{
        //N[i] =N_o*tay_exp(lamb*t[i], &k, &err_f);
        //t[i+1] = t[i] + 1;
        //printf("%0.8Lf %0.8Lf\n", t[i],N[i]);
    //}
    printf("-------------------------------------------------------------------\n");
    printf("Absolute error = Litrature Value - Calculated Value\n");
    printf("Relative Error = (|N[i+1]-N[i]|)/N[i+1]*100%%\n");
    printf("-------------------------------------------------------------------\n");
    printf("Argument for the function is %Lf\n", t[0]);
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    N[0] = N_o*tay_exp(lamb*t[0], &k, &err_f);
    N[1] = N_o*exp(lamb*t[0]);
    printf("-------------------------------------------------------------------\n");
    err = ((N[1]-N[0])/N[1])*100;
    printf("Value from series (Number of Atoms left after decay): %0.2Le\n", (N[0]));
    printf("Values from inbuilt function function (Number of Atoms left after decay): %0.2Le\n", (N[1]));

    //printf("Error in the final value (Absolute)%f%%\n", fabs(err));
    //printf("Error in the final value (Iterative)%f%%\n", fabs(err_f));
    //printf("%d\n", k);
}


