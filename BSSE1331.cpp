#include<bits/stdc++.h>
#define f(x)=c1+c2*x+c3*x*x+c4*x*x*x
int main()
{
   double A[11][4]=    { {1,0,0,0},{1,0.2,0.04,0.008},{1,0.4,0.16,0.064},{1,0.6,0.36,0.216},
                                       {1,0.8,0.64,0.512},{1,1,1,1},{1,1.2,1.44,1.728},{1,1.4,1.96,2.744},
                                        {1,1.6,2.56,4.096},{1,1.8,3.24,5.832},{1,2,4,8}
                                    };



    double B[11][1]={1,1.04,1.16,1.36,1.64,2.0,2.44,2.96,3.56,4.24,5};

    double ATrans[4][11];

    for(int i=0;i<4;i++)
      {
        for(int j=0;j<11;j++)
           {
             ATrans[i][j]=A[j][i];
           }
       }
     printf("\n\nA Matrix is :\n");

     for(int i=0;i<11;i++)
    {
      for(int j=0;j<4;j++)
          {
            printf("%lf  ",A[i][j]);
          }
          printf("\n");
     }

    printf("\n\nB matrix is :\n");
    for(int i=0;i<11;i++)
       {
         for(int j=0;j<1;j++)
            {
              printf("%lf  ",B[i][j]);

             }
             printf("\n");
        }



    printf("Transpose Matrix(AT) is:\n");
    for(int i=0;i<4;i++)
       {
         for(int j=0;j<11;j++)
            {
              printf("%lf  ",ATrans[i][j]);
             }
        printf("\n");

        }


  double mulA[4][4];

  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
      {
         mulA[i][j]=0;

           for(int k=0;k<11;k++)
            {
              mulA[i][j]+=ATrans[i][k]*A[k][j];
             }
           }
       }

     printf("\n\nMultiplication Matrix is(AT*A) :\n");
       for(int i=0;i<4;i++)
          {
            for(int j=0;j<4;j++)
               {
                  printf("%lf  ",mulA[i][j]);
               }

               printf("\n");

          }


    double mulB[4][1];
    for(int i=0;i<4;i++)
       {
         for(int j=0;j<1;j++)
           {
             mulB[i][j]=0;
             for(int k=0;k<11;k++)
                {
                  mulB[i][j]+=ATrans[i][k]*B[k][j];
                  }

               }
        }

      printf("\n\nMultiplication Matrix(AT*B) is :\n");

          for(int i=0;i<4;i++)
          {
            for(int j=0;j<1;j++)
               {
                  printf("%lf  ",mulB[i][j]);
               }

               printf("\n");

          }
          int i,j;
      double obM[4][4+1];
      for( i=0;i<4;i++)
         {
           for(j=0;j<4;j++)
             {
               obM[i][j]=mulA[i][j];
              }

             obM[i][j]=mulB[i][0];
           }

      printf("\n\nObmanted Matrix is :\n");
         for(i=0;i<4;i++)
         {
           for(j=0;j<4+1;j++)
             {
               printf("%lf  ",obM[i][j]);
              }

             printf("\n");
           }


    double M,L;
    int k;

for (i=0; i<4; i++) {
    L = obM[i][i];
    for (j=i; j<4+1; j++) {
        obM[i][j] = obM[i][j]/L;
    }

    for (k=0; k<4; k++) {
      if (k != i) {
        M = -obM[k][i];
        for (j=i; j<4+1; j++) {
          obM[k][j] = obM[k][j] + M*obM[i][j];
        }
      }
    }
  }


  printf("\n\nDiagonal Matrix is :\n");
         for(i=0;i<4;i++)
         {
           for(j=0;j<4+1;j++)
             {
               printf("%lf  ",obM[i][j]);
              }

             printf("\n");
           }

printf("\n\nFinal answer (X)= \n");
for(int i=0;i<4;i++)
   {
     for(int j=4;j<4+1;j++)
     {
     printf("%lf    ",obM[i][j]);
     }
     printf("\n");

   }
  printf("\n");

return 0;
}
