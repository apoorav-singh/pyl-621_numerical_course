// 31-03-2021

#include<stdio.h>
#include<math.h>

// Decimal to Binary Converter

int Decimal_to_Binary(double n1, int j1, int j2)
{
    printf("Binary equivalent of the Entered Number = ");
    if(n1<0)
    {
        printf("-");
        n1 = fabs(n1);
    }
    else
    {
        printf(" ");
    }
    int rem,i;
    long long inte_bin=0, res_inte[j2], res_deci[j1];
    double deci_bin=0,place_h,res=0.0,err_ab,err_rel;
    inte_bin = (int)n1;
    deci_bin = n1 - inte_bin;

    // For Integer Part

    //for(i=0;i<j2;i++)
    //{
       // res_inte[i] = 0;
    //}

    for(i=0;i<j2;i++)
    {
        rem = inte_bin%2;
        inte_bin = inte_bin/2;
        res_inte[i] = rem;
        //printf("%lld",res_inte[i]);
    }

    // For printing the decimal array

    for(i=(j2-1);i>=0;i--)
    {
        printf("%lld",res_inte[i]);
    }
    printf(".");

    // For Decimal Part

    place_h = deci_bin;
    for(i=0;i<j1;i++)
    {
        place_h = place_h*2;
        res_deci[i] = (int)place_h;
        place_h = place_h - (int)place_h;
        printf("%lld", res_deci[i]);
    }
    printf("\n");

    // Calculation of the error 
    // Only conversion to the left side of decimal is being done as error will only arise from there.

    // Conversion from calculated decimal to binary.
    for(i=1;i<=j1;i++)
    {
        res += pow(2,-i)*res_deci[i-1];
    }

    // Result Printing 

    res += (int)n1;
    printf("Computed Value: %lf\n",res);
    err_ab = fabs(res - n1);
    err_rel = err_ab/n1*100;
    printf("Absolute Error: %lf | Relative Error: %lf%%\n", err_ab, err_rel);

    return 1;
}

void main()
{
    double n;
    int j1 = 8, j2 = 16;
    printf("Enter the number for Decimal to Binary Conversion: ");
    scanf("%lf", &n);
    // j1 is maximum range for decimal side calculation
    // j2 is maximum range for integer side calculation 
    Decimal_to_Binary(n,j1,j2);
}