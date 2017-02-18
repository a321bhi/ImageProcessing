#include<stdio.h>
#include<conio.h>
#include<math.h>
//#include<complex.h>
//#define N 8
//#define PI 3.14159265
#define N 20
int main()
{
    int i=0,j=0,k = 0;
    int x[N], h[N];
    int num_x,num_h;
    int a,z,sum;
    printf("Enter number of elements in x: \n");
    scanf("%d",&num_x);
    printf("Enter number of elements in h: \n");
    scanf("%d",&num_h);
    int conv[num_h][num_x];
    int total = num_x+num_h;
    int y[total];
    printf("Enter the elements of x:\n");
    for(i=0;i<num_x;i++){
      scanf("%d",&x[i]);
    }
    printf("Enter the elements of h:\n");
    for(i=0;i<num_h;i++){
      scanf("%d",&h[i]);
    }
    for(i=0;i<num_h;i++){
      for(j=0;j<num_x;j++){
        conv[i][j]=x[j]*h[i];
      }
    }
    for(i=0;i<num_h;i++){
      for(j=0;j<num_x;j++){
        printf("%d ",conv[i][j]);
      }
      printf("\n");
    }
    a=0;z=0;
    for(i=0;i<total;i++){
      y[i]=0;
    }
    for(i=0;i<num_h;i++){
      z++;
      for(j=0;j<num_x;j++){
        y[a]+=conv[i][j];
        a++;
      }
      a=z;
    }
    printf("The result is:\n");
    for(i=0;i<total-1;i++){
      printf("%d\t",y[i]);
    }
}
