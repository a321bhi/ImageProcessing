#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int hist[256];
    float pdf[256],cdf[256];
    int buffer1,a=0,b=0;
    int buffer2=0;
    int i=0,j=0,k = 0;
    FILE *infile,*outfile;

    int data[256][256]={0};
    int sum,total;

    infile=fopen("PictureName.bmp","rb");
    if (infile==0)
    {
       printf("File Not found");
       getch();
    }

    outfile=fopen("lpf.bmp","wb+");
    if (outfile==0)
    {
       printf("File Not created");
       getch();
    }
    for(i=0;i<1078;i++)
    {
     a=fgetc(infile);
     fputc(a,outfile);
        //fread(&buffer1,sizeof(char),1,infile);
        //fwrite(&buffer1,sizeof(char),1,outfile);
    }
    for(i=0;i<256;i++){
      hist[i]=0;
      cdf[i]=0;
      pdf[i]=0;
    }
    int highest=0;

    //get input from file
    for(i=0;i<256;i++)
    {
        for(j=0;j<256;j++)
        {
            a=fgetc(infile);
           //fread(&buffer1,sizeof(char),1,infile);
          data[i][j] = a;//buffer1;
          hist[a]++;
         }
    }
    int N=0;
    //calculate the Total number of pixels
    for(i=0;i<256;i++){
      N+=hist[i];
    }
    //calculate pdf
    for(i=0;i<256;i++){
      pdf[i]=hist[i]/N;
    }
    cdf[0]=pdf[0];
    //calculate cdf
    for(i=1;i<256;i++){
      cdf[i]=pdf[i]+cdf[i-1];
    }
    //Denormalise cdf
    for(i=0;i<256;i++){
      cdf[i]*=7;
    }
    
    for(i=0;i<256;i++)
    {
        for(j=0;j<256;j++)
        {
            if(i==0 || j==0 ||i==255 ||j==255)
            {
                fputc(data[i][j],outfile);
             //fwrite(&data[i][j],sizeof(char),1,outfile);
            }
            else
            {
            sum=data[i-1][j-1]+data[i-1][j]+data[i-1][j+1]+data[i][j-1]+data[i][j]+data[i][j+1]+data[i+1][j-1]+data[i+1][j]+data[i+1][j+1];
            total=sum/9;
                 fputc(total,outfile);
            //fwrite(&total,sizeof(char),1,outfile);
            }
        }
    }

    fclose(infile);
    fclose(outfile);
    getch();
}
