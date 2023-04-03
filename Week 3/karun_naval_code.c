
#include <stdio.h>
 #include<math.h> 
void main()
 {
   double num,b, binary, dec=0,c,fdec=0,b2d,Et,Er;
  int rem[16],a, bin=0,i=1,j=1,frem[8],fbin=0,k=1,l,rem1,bb;
   printf("\nEnter the decimal number\n");
   scanf("%lf",&num);
   for(l=0;l<16;l++)
     { rem[l]=0;}
  // if (num>65536||num<-65536)
    // break;
 if (num<65536 || num>-65536)
    {a = (int)num;
     b = num-a;
    //printf("\n%lf\t%lf",a,b);
  while(a!=0)
   {
      rem[k] = a%2;
     bin+= rem[k]*i;
     //printf("%d",rem[k]);
     a/= 2;
      i*=10;
      k++;
     }
   printf("\nbinary number=%d.",bin);
    c = b;
    for(j=1;j<=8;j++)
     {
      c = c*2;
       //printf("\nc=%lf\t\n",c);
      frem[j] = (int)c;
       //printf("\nc=%lf\t\n",c);
       fbin+=frem[j]*k;
       printf("%d",frem[j]);
       c = c - frem[j];
       k*=10;
       }
     //printf("\nbinary number=%d\t",bin);
    }
   else
    printf("Entered num is not in the range");
   
   // binary to decimal 


    bb = bin;
   i=0;
   //printf("\nbb=%d\t",bb);
      while(bb!=0)
     {
       rem1=bb%10;
       dec+= (rem1*pow(2,i));
       bb/=10;
       i++;
      }
    //dec = pow(rem[16],16);
   // printf("%lf\t",dec);
    
   for(j=1;j<=8;j++)
    {
     fdec+= frem[j]*pow(2,-j);
    }
    //printf("%lf\t",fdec);
   b2d = dec+fdec;
   printf("\nbinary to decimal = %lf\t",b2d);
   Et = num-b2d;
   printf("\n true error=%lf\t",Et);
   Er = 100*(Et/num);
   printf("\n relative Erorr = %lf\n",Er);


  // }
//printf("\n%lf",dec);
}
