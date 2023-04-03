#include<stdio.h>
#include<math.h>


double ana(double x1)
{
	double g=9.8,c=12.5, m=68.1;
	double z = (g*m/c)*(1-exp(-c/m*x1));
	return z;
}

void main()
{
	int i,N,a;
	double h, x_beg=0.0, x_end=100.0, g=9.8,c=12.5, m=68.1;
	char fn[20];

	printf("Enter 0 for analytical treatment else other integer for Numerical treatment: ");
	scanf("%d", &a);	
	printf("Enter the step value for the function, Enter 0.5 for analytical treatment.\n");
	scanf("%lf", &h);
	printf("Enter the file name, Make sure it is not too long: ");
	scanf("%s", fn);

	N=(x_end-x_beg)/h;
		

	if(a==0)
	{
		double t[N],v[N];
		FILE *fp = fopen(fn,"w");
		t[0] = 0.0;
		
		for(i=0;i<=N;i++)
		{
			v[i]=ana(t[i]);	
			t[i+1] = t[i]+h;
			fprintf(fp,"%lf %lf\n",t[i],v[i]);
		}
		fclose(fp);
	}
	
	else
	{	
		int z=1000;		
		double t[z],v[z];
		FILE *fp = fopen(fn,"w");
		t[0] = 0;
		v[0] = 0;
		v[1] = v[0] + (g-(c/m)*v[0])*h;
		
		for(i=1;i<=z;i++)
		{
			if((v[i]-v[i-1]) <= 1e-3)
			{
				break;
			}
			else
			{
				v[i+1] = v[i] + (g-(c/m)*v[i])*h;
				t[i+1] = t[i] + h;
				fprintf(fp,"%lf %lf\n",t[i],v[i]);
				//printf("%lf %lf\n",t[i],v[i]);
					
			}
		}

		fclose(fp);
					
	}
}

