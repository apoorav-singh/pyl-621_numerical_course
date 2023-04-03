// Parachute problem

#include<stdio.h>
#include<math.h>

double ana(float x1)
{
    double g=9.8,c=12.5,m=68.1;
    double z=(g*m/c)*(1-exp(-c/m*x1));
    return z;
}

void main()
{
    int i,j=0,N,a;
    double h,x_beg=0.0,x_end=100, g=9.8,c=12.5,m=68.1;
    printf("Enter 0 for anaylitical solution or any other number for numerical one: ");
    scanf("%d", &a);

    printf("Enter the step value, i.e. 2,1 etc. Enter 0.5 for analytical solution.\n");
    scanf("%lf",&h);

    N=(x_end-x_beg)/h; 
    
    double x[N],v[N];
    
    char fl[20];
    printf("Enter the file name, make sure that it shouldn't be more than 10 characters long\n");
    scanf("%s",fl);
    
    if(a==0)
    {
        FILE *fp = fopen(fl,"w");
        x[0] = x_beg;
        for(i=1;i<=N;i++)
        {
            v[i]=ana(x[i]);
            x[i+1]=x[i]+h;
            fprintf(fp,"%lf %lf\n",x[i],v[i]);
        
        }
        fclose(fp); 
    }

    else
    {
        FILE *fp = fopen(fl,"w");
        //Declaring initial values

        v[0] = 0.0;
        x[0] = x_beg;
        x[1] = x[0] + h;
        v[1]=v[0]+(g-(c/m)*v[0])*h;

        for(i=1;i<=N;i++)
        {   
            if((v[i]-v[i-1]) == 1e-4)
            {
                break; 
            }

            else
            {
                v[i+1]=v[i]+(g-(c/m)*v[i])*h;
                x[i+1]=x[i]+h;
                fprintf(fp,"%lf %lf\n",x[i],v[i]);
            }
            
        }

        fclose(fp);
    } 
}
