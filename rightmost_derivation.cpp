#include<bits/stdc++.h>
using namespace std;

void printString(string s)
{
         int flag=0;
         string s1,s2;
        for(int i=0;i<s.length();i++)
       {
           if(s[i]=='1' )
           {
               flag = i;
            break;
           }
        }
            cout<<" -->A1B";
             for(int i = flag+1; i< s.size();i++)
             {
                 if(s[i]=='0')
                    s2+="0";
                 else if(s[i]=='1')
                {
                    s2+="1";
                 }
                 cout<<" -->A1"<<s2<<"B";

                if(i==s.size()-1)
                {
                    cout<<" -->A1"<<s2<<"e";
                    cout<<" -->A1"<<s2;
                }
             }
            if(s[0]=='1')
                cout<<" ---> "<<"e1"<<s2;
            for(int i=0; i<flag; i++)
            {
                s1+="0";
                 cout<<" ---> "<<s1<<"A1"<<s2;
                 if(flag==i+1)
            {
                cout<<" ---> "<<s1<<"e1"<<s2;
                cout<<" ---> "<<s1<<"1"<<s2;
            }
            }
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
        cout<<"Right most derivation is  : ";
        printString( s);

    }
}
