#include<stdio.h>
#include<conio.h>
#include<math.h>
//#include<complex.h>
#define N 8
#define PI 3.14159265
int main()
{
    int i=0,j=0,k = 0;
    double val;
    double W[N][N][2];
    double x[N][2] ={{3.18,0},{-2.16,-1.46},{0.71,1.06},{-0.66,-0.04},{1.06,0.0},{-0.66,0.04},{0.71,-1.60},{-2.61,1.46}};
    double ans[N][2];
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        W[i][j][0] = (cos((2*PI*(i)*(j))/N))/8;
        W[i][j][1] = (sin((2*PI*i*j)/N))/8;
      }
    }
/*    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        printf("%.2f ",W[i][j][0]);
        printf("%.2f\t",W[i][j][1]);
      }
      printf("\n");
    }*/
    long double sum,sum1;
    for(i=0;i<N;i++){
      sum=0;sum1=0;
      for(j=0;j<N;j++){
        sum+=W[i][j][0]*x[j][0];
        sum1+=W[i][j][1]*x[j][1];
      }
      ans[i][0]=sum/(N-1);
      ans[i][1]=sum1/(N-1);
    }
    for(i=0;i<N;i++){
      printf("%.2f + (%.2f) i\n",ans[i][0],ans[i][1]);
    }
}
