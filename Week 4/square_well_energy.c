// Actual Energy is computed in this program.

#include<stdio.h>
#include<math.h>

void main()
{
	
	int i,n=10000;
	float sum1[n],sum2[n],pi=(float)M_PI,hbar=1.0,m=1.0,a=1.0,n1,act_s,err_1,err_2;

	act_s = (480*hbar*hbar)/(pow(pi,4)*m*a)*pow(pi,4)/96; //

	printf("Actual Sum of the series: %0.12f\n",act_s);

	printf("\n");

	for(i=0;i<=n;i=i+1)	
	{	
		sum1[i] = 0;
		sum2[i] = 0;
	}

// For printing the forward summastion

	for(i=1;i<=n;i++)	
	{	
		if(i%2 == 0)
		{
			sum1[i] = sum1[i-1] + 0;
			//printf("%lf\n",sum1[i]);			
		}
		else
		{
			n1 = i;
			sum1[i] =sum1[i-1] +  (480*hbar*hbar)/(pow(pi,4)*m*a)*(1/pow(n1,4)); //
			//printf("%lf\n",sum1[i]);
		}

	}

	printf("Sum of the series from forward sumastion: %0.12f\n",sum1[n]);		

	printf("\n");

// For printing the backward summastion

	for(i=(n-1);i>=1;i--)	
	{	
		if(i%2 == 0)
		{
			sum2[i] = sum2[i+1] + 0;
			//printf("%lf\n",sum2[i]);			
		}
		else
		{
			n1 = i;
			sum2[i] = sum2[i+1] + (480*hbar*hbar)/(pow(pi,4)*m*a)*(1/pow(n1,4));
			//printf("%lf\n",sum2[i]);
		}

	}

	printf("Sum of the series from backward sumastion: %0.12f\n",sum2[1]);
	printf("\n");

// To print the error
	//printf("Iteration Number | Forward Sumastion | Relative Error in F.S. | Backward Sumastion | Relative Error in B.S.|\n");
	for(i=1;i<n;i++)
	{
		
		err_1 = (sum1[i] - act_s)/act_s*100;
		err_2 = (sum2[n-i] - act_s)/act_s*100; 
		
		printf(" %5.d               |  %0.10f        |  %0.3e%%            |  %0.10f         |    %0.3e%%         | \n", i, sum1[i], fabs(err_1), sum2[n-i], fabs(err_2));
	}
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------");

	
}

