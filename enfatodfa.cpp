#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("enfa.txt","r",stdin);
    int states_num,inputs;
    cin>>states_num>>inputs;
    char matri[states_num][inputs][states_num];
    map<int,string>arr;
    map<char,int>arr1;
    map<int,string>epsilon;
    char ch;

    for(int i=0;i<states_num;i++)
    {
           cin>>ch;
           arr[i]=ch;
           arr1[ch]=i;
    }

     for(int i=0;i<states_num;i++)
     {
        for(int j=0;j<inputs;j++)
        {
            for(int k=0;k<states_num;k++)
            {
                cin>>matri[i][j][k];
            }
        }
     }
       cout<<"    E-NFA table"<<endl;

      for(int i=0;i<states_num;i++)
     {
        for(int j=0;j<inputs;j++)
        {
            for(int k=0;k<states_num;k++)
            {
                cout<<matri[i][j][k]<<" ";
            }
            cout<<"|";
        }
        cout<<endl;
     }



     for(int i=0;i<states_num;i++)
     {
         epsilon[i]=arr[i];
         for(int j=0;j<states_num;j++)
         {
             if(matri[i][inputs-1][j]!='0' && epsilon[i]!=to_string(matri[i][inputs-1][j]))
             {
             epsilon[i]+=matri[i][inputs-1][j];
             }
         }
     }


     for(int i=0;i<states_num;i++)
     {
         for(int j=1;j<epsilon[i].length();j++)
         {
             if(epsilon[arr1[epsilon[i][j]]].length()>1)
             {
                 for(int k=1;k<epsilon[arr1[epsilon[i][j]]].length();k++)
                 {
                     if(epsilon[i].find(epsilon[arr1[epsilon[i][j]]][k])== -1)
                     {
                         epsilon[i]+=epsilon[arr1[epsilon[i][j]]][k];
                     }
                 }
             }
         }
     }

        cout<<" Epsilons"<<endl;
        for(int i=0;i<states_num;i++)
     {
             cout<<arr[i]<<" ---> "<<epsilon[i]<<endl;
     }



     map<int,map<int,string>>newstatematric;



     int power=pow(2,states_num);
     string arrofnewstates[power];
     arrofnewstates[0]=epsilon[0];

     map<string,int>newstates;
     newstates[epsilon[0]]=1;

     vector<char>eachstate;
     int start=0,end=1;



     while(start<end)
     {
            for(int x=0;x<inputs-1;x++)
             {
                 for(int i=0;i<arrofnewstates[start].length();i++)
                 {
                     if(matri[arr1[arrofnewstates[start][i]]][x][0]!='0')
                     {
                        for(int j=0;j<states_num;j++)
                        {
                        if(matri[arr1[arrofnewstates[start][i]]][x][j]!='0')
                            {
                                eachstate.push_back(matri[arr1[arrofnewstates[start][i]]][x][j]);
                            }
                            else
                            {
                                break;
                            }
                        }
                     }
                 }

                         for(int l=0;l<eachstate.size();l++)
                         {
                             for(int k=0;k<epsilon[arr1[eachstate[l]]].length();k++)
                             if(newstatematric[start][x].find(epsilon[arr1[eachstate[l]]][k])==-1)
                             {
                                 newstatematric[start][x]+=epsilon[arr1[eachstate[l]]][k];
                             }
                         }

                 eachstate.clear();
                 if(newstates[newstatematric[start][x]]!=1)
                 {
                     arrofnewstates[end]=newstatematric[start][x];
                     end++;
                 }

                 newstates[newstatematric[start][x]]=1;
             }
             start++;
     }
     cout<<"    DFA table"<<endl;
     for(int i=0;i<newstates.size();i++)
     {
         cout<<arrofnewstates[i]<<" ---> ";
         for(int j=0;j<inputs-1;j++)
         {
             cout<<newstatematric[i][j]<<" |";
         }
         cout<<endl;
     }



    return 0;
}

