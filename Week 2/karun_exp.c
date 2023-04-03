// to calculate the number of radioactive decaying particles 
#include <stdio.h>
 #include<math.h> 
// Returns approximate value of e^x 
// using sum of first n terms of Taylor Series
void exponential(int n, float x, float* sum,float* er,float* ea)
{
    float sum1[100],y ,t=1,er1,ea1; // initialize sum of series
  sum1[0] = 1.0f;
  y = exp(x);
    for (int i = 1; i <=n ; i++ )
        {  
            t = t*x/i;
            sum1[i] = (sum1[i-1] + t);
            *sum = sum1[i];
            ea1 = (y - sum1[i]);
            *ea = fabs(ea1);
             er1 = 100*(sum1[i] - sum1[i-1])/sum1[i]; 
             if (fabs(er1)<=0.001)
             {
              break;
             }
            *er = fabs(er1);
            
         //sum = fabs(-1);
         }
         
    //return sum;
}
  
// Driver program to test above function
int main()
{
    int n = 10,i=0;
    float x,sum,er,ea,y;
    float Tf,lem,Na,N0,mass,mo,N,t,exp1;
    exp1 = 1;
    Na = 6.022e23;//*pow(10,23);
    mass = 2; t = 4.869;
    mo = 237.0487;
    N0= (Na*mass)/mo;
    Tf = 6.75;
    lem = 0.693/Tf;
    x = -lem*t;
    y = exp(x);
    printf("True value of e^x = %f\t",y);
    printf("\nfirst term of e^x = %f\t",exp1);
    for(i=1;i<n;i++)
    {
       exponential(i, x,&sum,&er,&ea);
      // if(er<0.01)
       //break;
       printf("\nIteration %d\t e^x = %f\t\tREror = %f%%\t\tAEror = %f\n",i,sum,er,ea );
    }
    N = N0*sum;
    printf("\nAfter  %f days remaining nuclei N= %f\n",t,N);
    return 0;
}

