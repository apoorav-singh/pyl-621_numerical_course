#include<stdio.h>
#include<math.h>


void main()
{
    int i=1,n;
    long double ser, j=1.0,sum=1.0, pi=3.142857, er;
    // Analytic value of pi is 3.142857
    printf("Enter the number of terms in the series: ");
    scanf("%d",&n);

    while(i<=n)
    {   
        ser = pow(-1,i)*(1/(j+2));
        //printf("%Lf \n", ser);
        sum += ser;
        j+=2;
        i+=1;
    }
    sum = sum*4.0;
    printf("Estimated value of pi is: %Lf\n", sum);

    // Error Calcultion
    er = ((sum-pi)/pi)*100;
    printf("Error in value of pi (upto 6 decimal places) is = %Lf%%\n", er);


    
}