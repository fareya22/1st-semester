#include<bits/stdc++.h>
using namespace std;
int matrix[100][100];


void floyd_Warshall()
{
int i, j, k;

	for (k = 1; k <=10; k++) {
		for (i = 1; i <=10; i++) {
			for (j = 1; j <=10; j++) {
				if (matrix[i][k] + matrix[k][j] <matrix[i][j])
					matrix[i][j] =matrix[i][k] + matrix[k][j];
			}
		}
	}
	double sum=0.000,cnt=0.000;

	for (i = 1; i <=100; i++) {
			for (j = 1; j <=10; j++) {
				if (i!=j&&matrix[i][j]!=10000)
                {
                    cnt++;
                    sum=sum+matrix[i][j];
                }

			}
		}
cout<<"average length between pages :"<<sum/cnt<<"\n\n";
}


int main(void)
{

        for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
            matrix[i][j]=100000;

      int u,v;
      while(1)
      {
          cout<<"enter the vertexes";
          cin>>u>>v;
          if(u==0&&v==0)break;
          matrix[u][v]=1;
      }

      floyd_Warshall();


      cout<<"\n\n";

}
