#include <bits/stdc++.h>
using namespace std;

int main() {

int t;
cin>>t;
while(t--)
{
    int x,n;
    int a1;
    vector<double>v;
    cin>>n;
    cin>>x;
    for(int i=0;i<n;i++)
  {
     cin>>a1;
      v.push_back(a1);
  }
  sort(v.begin(),v.end());
  cout<<v[n-1]<<endl;
}
	return 0;
}

