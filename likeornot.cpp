#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p0=0,ne=0;
        cin>>n;
        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i]>0)
               p0++;
            else
                ne++;
        }

        int p1=p0,n1=ne,score=0;
        for(int i=0;i<n;i++)
        {
            if(p0>0)
               {
                    score++;
                      p0--;
               }
               else
               {
                    score--;
                      ne--;
               }
        cout<<score;
        }
        cout<<endl;
        p0=p1,ne=n1;
        for(int i=0;i<n;i++)
        {
             if(ne>0 && (i%2)==0)
             {
                 score--;
                 ne--;
             }
            else
            {
                score++;
                p0 --;
            }
            cout<<score;
        }
        cout<<endl;
    }
}
