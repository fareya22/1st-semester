#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];

void floyd_Warshall(int maximum)
{
int i, j, k;
	for (k = 1; k <= maximum; k++) {
		for (i = 1; i <= maximum; i++) {
			for (j = 1; j <= maximum; j++) {

				if (matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}
	double sum=0.000,cnt=0.000;

	for (i = 1; i <= maximum; i++) {

			for (j = 1; j <= maximum; j++) {

				if (i!=j&&matrix[i][j]<100000)
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

    while(1)
    {

        for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            matrix[i][j]=100000;

        int u,v,ux,vx,cnt=0,maximum=0;
      while(1)
      {

          cout<<"enter the vertexes";

          cin>>u>>v;
          if(u>maximum)maximum=u;
          if(v>maximum)maximum=v;

          if(u==0&&v==0)break;

          else cnt++;
          matrix[u][v]=1;

      }

      if(cnt==0)break;

      floyd_Warshall(maximum);


      cout<<"\n\n";

    }
}
