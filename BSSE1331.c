#include<stdio.h>
#define f(x) = c1+c2*x+c3*x*x+c4*x*x*x
int main()
{
     double A[11][4]=  { {1,0,0,0},{1,0.2,0.04,0.008},{1,0.4,0.16,0.064},{1,0.6,0.36,0.216},
                                        {1,0.8,0.64,0.512},{1,1,1,1},{1,1.2,1.44,1.728},{1,1.4,1.96,2.744},
                                        {1,1.6,2.56,4.096},{1,1.8,3.24,5.832},{1,2,4,8}
                                      };

     double B[11][1]={1,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5};

     double Atranspose[4][11];
     int i,j,k;
     for(i = 0;i<4 ;i++)
     {
         for(j=0; j<11;j++)
         {
             Atranspose[i][j] = A[j][i];
         }
     }

      printf("Transpose matrix of A :\n");

      for(i = 0;i<4 ;i++)
     {
         for(j=0; j<11;j++)
         {
             printf( "  %lf",Atranspose[i][j] );
         }
         printf("\n");
     }

     double AT_A_multi[4][4];

      for( i=0;i<4;i++)
    {
      for( j=0;j<4;j++)
      {
         AT_A_multi[i][j]=0;

           for(int k=0;k<11;k++)
            {
              AT_A_multi[i][j]+=Atranspose[i][k]*A[k][j];
             }
        }
       }


    printf("\nMaltiple matrix of AT*A is :\n");

      for(i = 0;i<4 ;i++)
     {
         for(j=0; j<4;j++)
         {
             printf( "  %lf",  AT_A_multi[i][j] );
         }
         printf("\n");
     }


     double AT_B_multi[4][1];

   for( i=0;i<4;i++)
    {
      for( j=0;j<1;j++)
      {
         AT_B_multi[i][j]=0;

           for(int k=0;k<11;k++)
            {
              AT_B_multi[i][j]+=Atranspose[i][k]*B[k][j];
             }
        }
       }

    printf("\nMaltiple matrix of AT*B is :\n");

      for(i = 0;i<4 ;i++)
     {
         for(j=0; j<1;j++)
         {
             printf( "  %lf",  AT_B_multi[i][j] );
         }
         printf("\n");
     }

     //gauss jordan elimination method

     double Augmented[4][5];

    for(i = 0;i<4 ;i++)
     {
         for(j=0; j<4;j++)
         {
           Augmented[i][j] = AT_A_multi[i][j]  ;
         }
          Augmented[i][4] = AT_B_multi[i][0] ;
     }

     printf("\nAugmented matrix  is :\n");

      for(i = 0;i<4 ;i++)
     {
         for(j=0; j<5;j++)
         {
             printf( "  %lf",  Augmented[i][j] );
         }
         printf("\n");
     }

      double p,q;

    for (i=0; i<4; i++)
    {
    q = Augmented[i][i];
    for (j=i; j<5; j++)
    {
        Augmented[i][j] = Augmented[i][j]/q;
    }

    for (k=0; k<4; k++)
    {
      if (k != i)
       {
        p = -Augmented[k][i];
        for (j=i; j<5; j++)
        {
          Augmented[k][j] =Augmented[k][j] + p*Augmented[i][j];
        }
      }
    }
  }


  printf("\nDiagonal Matrix is :\n");
         for(i=0;i<4;i++)
         {
           for(j=0;j<5;j++)
             {
               printf("%lf  ",Augmented[i][j]);
              }

             printf("\n");
           }

    printf("\n\nFinal Result  Ci= \n");
    for(i=0;i<4;i++)
   {
     for(j=4;j<5;j++)
     {
     printf("%lf    ",Augmented[i][j]);
     }
     printf("\n");

   }
  printf("\n");


return 0;
}


