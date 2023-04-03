#include<stdio.h>
#include<math.h>



void main()
{
    int N=4;
    double e=2.718;

// printf("Enter the number of data points: ");
// scanf("%d", &N);

// m is for slope and c is for intercept

    double m,c,T[N],x[N],y[N],rel_err_c, y_6;
// char fl_name[100];
// printf("Enter the file name: ");
// scanf("%c", &fl_name);

// to compute least square fit
    double rel_err_m,sx=0, sy=0, sxy=0, sx2=0;

//Opening the file
    FILE *fp=fopen("data_2.dat","r");

// Reading from the file

    for (int i=0; i<N; i++)
    {
        fscanf( fp, "%lf %lf", &T[i], &y[i]);
        x[i] = pow(e,T[i]/4);
        sx += x[i];
        sy += y[i];
        sxy += x[i]*y[i];
        sx2 += x[i]*x[i];
    }

fclose(fp);

//Opening the file
    FILE *fp2=fopen("data_3_lin.dat","w");

// Reading from the file

    for (int i=0; i<N; i++)
    {
        fprintf(fp2, "%lf %lf\n", x[i],y[i]);
    }

    fclose(fp2);


    m=(N*sxy-sx*sy)/(N*sx2-sx*sx);
    c=(sy-m*sx)/N;

    printf("Function obtained is y = %lf*x + (%lf)\n", m,c);

    rel_err_c = fabs(fabs(c) - 24.22944837)/24.22944837*100;
    rel_err_m = fabs(fabs(m) - 35.64614145)/35.64614145*100;
    printf("Value of the Intercept from the code %lf *C and error w.r.t. to literature value is: %lf%%\n", c, rel_err_c);
    printf("Value of the Slope from the code %lf *C and error w.r.t. to literature value is: %lf%%\n", m, rel_err_m);
    y_6 = m*6 +c;
    printf("Value of at y(6) = %lf *C\n", y_6 );
    //Writing the file
    FILE *fp1=fopen("fitted_2.dat","w");
    for (int j=0; j<N; j++) 
    {   
        fprintf(fp1, "%lf %lf\n", x[j],(x[j]*m+c));
    }
    fclose(fp1);

}