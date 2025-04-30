#include <bits/stdc++.h>
using namespace std;


int matrix[200][200];

int main()
{
    int node, street, query;
    int cases = 0;
    while (cin >> node >> street >> query)
    {
        if (node == 0 && street == 0 && query == 0)
            break;
        for (int i = 0; i <= node; i++)
       {
        for (int j = 0; j <= node; j++)
            {
                matrix[i][j] = 10000;
            }
         }

        int n1, n2, cost;
        for (int i = 0; i < street; i++)
        {
            cin >> n1 >> n2 >> cost;
            matrix[n1][n2] = matrix[n2][n1] = cost;
        }
        for (int k = 1; k <= node; k++)
        {
            for (int i = 1; i <= node; i++)
            {
                for (int j = 1; j <= node; j++)
                    matrix[i][j] = matrix[j][i] = min(matrix[i][j], max(matrix[i][k], matrix[k][j]));
            }
        }

        cout<<endl;

        int source[query],des[query];

        for (int i = 0; i < query; i++)
        {
            cin >> n1 >> n2;
            source[i]=n1;des[i]=n2;
        }

         cout << "Case #" << ++cases << endl;

        for (int i = 0; i < query; i++)
        {
            if (matrix[source[i]][des[i]] == 10000) cout << "no path"<<endl;
            else cout << matrix[source[i]][des[i]] << endl;
        }



    }

}
