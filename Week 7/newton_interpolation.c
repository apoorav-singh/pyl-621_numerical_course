// Code By: Apoorav Singh Deo
// Roll No: v19036

// This code cantains the algorithm for newton forward differnce 

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// 'n' takes the value for number of data points.
// 'x_arg' takes the argument for the given value that is to be computed
// 'x[]' Value for the x from the file
// 'f[]' Value for the function from the file

double newton_forward(int n, double x_arg, double  x[n], double f[n], double ana)
{
    printf("\n -----Newton's Forward Interpolation----- \n");

    double dif[n][n], func=0, b[n-1], prod[n], rel_err, ab_err;
    int i, j, k=1;

    // 'i' holds the value for the row
    // 'j' holds the value for the column
    // 'b[]' is the coefficient 
    // 'prod[]' would be computing the value of the (x-x0)(x-x1)(x-x2) . . .
 

    // Declaring whole array to be equal to 0

    for (j=0;j<n;j++)
    {
        for (i=0;i<n;i++)
        {
            dif[i][j] = 0;
        }
        
    }


    for (i=0;i<n;i++)
    {
        dif[i][0] = f[i];
        // printf("%lf\n", dif[i][0]);
    }
        
    for (j=0;j<(n-1);j++)
    {
        for (i=0;i<n;i++)
        // This inner loop is working uptill n as it does not matter, Even if the loop works till
        // end rest values are plugged to zero hence it will cause no issue 
        {
            if ((i+k) == (n-1))
            {
                break;
            }

            dif[i][j+1] = (dif[i+1][j] - dif[i][j])/(x[i+k] - x[i]);
            //printf("%lf\n", dif[i][j]);
        }
        //printf("------------\n");
        k += 1;
        // k value not act as the implementation of proper formula but help us to terminate the 
        // loop at adequate point, this same task can also be done using for loop
    }   

    // Extracting the coefficient from the 2-D array

    for (i=0;i<(n-1);i++)
    {
        b[i] = dif[0][i];
        // printf("%lf\n", b[i]);
    }

    // Computing the value using Newton's Interpolation

    for (i=0;i<(n-1);i++)
    {
        prod[i] = 1.0;
        // printf("%0.10lf\n", prod[i]);
    }

    // Calculation of x + x(x-x0) + x(x-x0)(x-x1) + . . . 
    for (j=1;j<(n-1);j++)
    {
        for (i=0;i<j;i++)
        {
            prod[j] *= (x_arg - x[i]);

        // printf("%0.10lf\n", prod[j]);
        }
        // printf("----------");
        // printf("%0.10lf\n", prod[j]);
    }

    // Printing the final result
    printf("\nO.P        Value Obtained        Absolute Error        Relative Error\n");
    for (i=0;i<n-1;i++)
    {
        func += b[i]*prod[i];
        ab_err = ana - func; 
        rel_err = fabs(ab_err)*100/ana;
        printf("%3d              %8.6lf            %8.6lf           %3.lf%%\n", (i+1), func, ab_err, rel_err);
    }








}