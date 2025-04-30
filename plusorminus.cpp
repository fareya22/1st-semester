#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
     int minali=0,biance=0,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0)
            minali+=arr[i];
        else
            biance+=arr[i];
    }
    if(minali>biance)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
}
