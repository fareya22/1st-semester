#include<bits/stdc++.h>
using namespace std;

void printString(string s)
{
         int track=0,flag=0;
         cout<<"-->A1B";
        for(int i=0;i<s.length();i++)
       {
           if(s[i]=='0' )
           {
               track++;
               cout<<" -->";
               for(int j=0;j<track;j++)
                cout<<s[j];
                cout<<"A1B";
           }

           else{
            flag = i;
            break;
           }
           }
                cout<<" -->";
            for(int j=0;j<track;j++)
                cout<<s[j];
                cout<<"e1B";

                 cout<<" -->";
            for(int j=0;j<track;j++)
                cout<<s[j];
                cout<<"1B";

             for(int i = flag+1; i< s.size();i++)
             {
                       cout<<" -->";
                   for(int j=0;j<track;j++)
                      cout<<s[j];
                      cout<<"1";
                  for(int p=flag+1;p<=i;p++)
                      cout<<s[p];
                      cout<<"B";
               }

                      cout<<" -->";
                 for(int p=0;p<s.size();p++)
                      cout<<s[p];
                      cout<<"e";

                     cout<<" -->";
                   for(int p=0;p<s.size();p++)
                      cout<<s[p];
}

int main()
{
     string line,s;
     int part1 = 0;
     ifstream myfile ("grammer.txt");
     cout<<"The given grammer is: "<<endl;
      if (myfile.is_open())
     {
      while ( getline (myfile,line) )
     {
      cout << line << '\n';
     }
       myfile.close();
     }
     else
        cout << "Unable to open file";

    cout<<"Enter the string : ";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
            part1++;
    }

    if(part1 == s.size() )
    {
        cout<<"String not accepted"<<endl;
    }
    else
    {
        cout<<"String is accepted"<<endl;
        cout<<"Left most derivation is  : ";
        printString( s);

    }
}


