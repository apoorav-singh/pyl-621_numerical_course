#include<stdio.h>
#include<math.h>

double slope(int N, double sx, double sy, double sxy, double sx2)
{
    double m=(N*sxy-sx*sy)/(N*sx2-sx*sx);
    return m;
}

double intercept(int N, double sx, double sy, double sxy, double sx2, double m)
{
    double c=(sy-m*sx)/N;
    return c;
}


void main()
{
    int N=5;

    // printf("Enter the number of data points: ");
    // scanf("%d", &N);

    // m is for slope and c is for intercept

    double m,c,x[N],y[N],rel_err;
    // char fl_name[100];
    // printf("Enter the file name: ");
        // scanf("%c", &fl_name);

    // to compute least square fit
    double sx=0, sy=0, sxy=0, sx2=0;

    //Opening the file
    FILE *fp=fopen("data.dat","r");

    // Reading from the file

    for (int i=0; i<N; i++)
    {
        fscanf( fp, "%lf %lf", &x[i], &y[i]);

        sx += x[i];
        sy += y[i];
        sxy += x[i]*y[i];
        sx2 += x[i]*x[i];
    }

    fclose(fp);

    //m=(N*sxy-sx*sy)/(N*sx2-sx*sx);
    //c=(sy-m*sx)/N;
    m = slope(N, sx, sy, sxy, sx2);
    c = intercept(N, sx, sy, sxy, sx2, m);

    printf("Function obtained is y = %lf*x - %lf\n", m,fabs(c));

    rel_err = fabs(fabs(c) - 4.74)/4.74*100;
    printf("Workfunction for silver from the code is %lf eV and error w.r.t. to literature value is: %lf%%\n", fabs(c), rel_err);

    //Writing the file
    FILE *fp1=fopen("fitted.dat","w");
    for (int j=0; j<N; j++) 
    {
        fprintf(fp1, "%lf %lf\n", x[j],(x[j]*m+c));;
    }
    fclose(fp1);


}