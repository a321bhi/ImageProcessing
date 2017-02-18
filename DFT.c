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
    double ans[N][2];
    double x[8]= {0,0,2,3,4,0,0,0};
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        W[i][j][0] = (cos((2*PI*i*j)/N)/sqrt(8));
        W[i][j][1] = (sin((2*PI*i*j)/N)/sqrt(8));

//        W[i][j][0] = (cos((2*PI*(i)*(j))/N))/sqrt(((cos((2*PI*(i)*(j))/N))*(cos((2*PI*(i)*(j))/N)))+((sin((2*PI*i*j)/N))*(sin((2*PI*(i)*(j))/N))));
//        W[i][j][1] = (sin((2*PI*i*j)/N))/sqrt(((cos((2*PI*(i)*(j))/N))*(cos((2*PI*(i)*(j))/N)))+((sin((2*PI*i*j)/N))*(sin((2*PI*(i)*(j))/N))));
      }
    }
    /*for(i=0;i<N;i++){
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
	if(i == 0 && j == 0){
		sum =	W[i][j][0]*x[j];
		sum1 = W[i][j][1]*x[j];
	}
	else{
	        sum+= W[i][j][0]*x[j];
	        sum1+= -(W[i][j][1]*x[j]);
	}
      }
      ans[i][0]=sum;
      ans[i][1]=sum1;
    }
    for(i=0;i<N;i++){
      printf("%.2f - (%.2f) i\n",ans[i][0],ans[i][1]);
    }
}
