

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double difference_backward(double y1, double y2, double h)
{
    double res;
    // Diffrentiating using Backward Difference Method
    res = (y1-y2)/h;
    //printf("%lf\n", res);
    return res;
}

double difference_centeral(double y1, double y2, double h)
{
    double res;
    // Diffrentiating using Central Difference Method
    res = (y2-y1)/(2*h);
    //printf("%lf\n", res);
    return res;
}

double difference_forward(double y1, double y2, double h)
{
    double res;
    // Diffrentiating using Forward Difference Method
    res = (y2-y1)/h;
    //printf("%lf\n", res);
    return res;
}

double potential(double x)
{
    double phi;
    // q=1
    // epsilon_0=1
    phi = 1/(4*M_PI*x);
    return phi;
}

double analytical(double x)
{
    double phi;
    // q=1
    // epsilon_0=1
    phi = 1/(4*M_PI*x*x);
    return phi;
}




int main()
{
    int i, j, n;
    double h=0.1, x_beg=1.0, x_end=5.0;

    // Defining total number of Iteration 

    n=(x_end-x_beg)/h;

    double phi_x[n], x[n], fwd[n], bkd[n], cent[n];

    // Generating the potential values
    
    x[0]=x_beg;
    
    for (i=0;(i+1)<n;i++)
    {
        phi_x[i]=potential(x[i]);
        x[i+1]=x[i] + h;
        // printf("%lf %lf\n", x[i], phi_x[i]);
    }

    // Using Forward Difference Method

    for (i=0;(i+1)<n;i++)
    {
        fwd[i] = -difference_forward(phi_x[i], phi_x[i+1], h);
        //printf("%lf %lf\n",x[i], fwd[i]);
    }

    // Using Backward Difference Method

    for (i=(n-2);i>0;i--)
    {
        bkd[i] = -difference_backward(phi_x[i], phi_x[i-1], h);
        // printf("%lf %lf\n",x[i], bkd[i]);
    }

    // Using Centeral Difference Method

    for (i=1;(i+3)<n;i++)
    {
        cent[i] = -difference_centeral(phi_x[i-1], phi_x[i+1], h);
        printf("%lf %lf\n",x[i], cent[i]);
    }



    for(j=0;(j+2)<n;j++)
    {
        printf("%lf %lf\n", x[j], fwd[j]);
    }


    for(j=1;(j+2)<n;j++)
    {
        printf("%lf %lf\n", x[j], bkd[j]);
    }


    for(j=0;(j+2)<n;j++)
    {
        printf("%lf %lf\n", x[j], cent[j]);
    }


    for(j=0;(j+2)<n;j++)
    {
        printf("%lf %lf\n", x[j], analytical(x[j]));
    }

}
