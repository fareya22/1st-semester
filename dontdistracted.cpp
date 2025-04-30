#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,s;
  cin >> n>>s;
   if(s==0)
   {
       if(n==1)
     {
         cout<<"0 0";
       return 0;
     }
     else
     {
       cout<<"-1 -1";
       return 0;
     }
   }
   vector<int>maxi;
   vector<int>mini;
   for(int i=0;i<n;i++)
   {
       int k=min(9,s);
       maxi.push_back(k);
       s-=k;
   }
   if(s>0)
    cout<<"-1 -1";
   // reverse(maxi.begin(),maxi.end());


  return 0;
}
