#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n1,n2;

    cout<<"enter the number of nonfinal state";
    cin>>n1;
    int nf[n1];

    cout<<"enter the nonfinal states"<<"\n";
    for(int i=0; i<n1; i++)cin>>nf[i];

    cout<<"enter the number of final state";
    cin>>n2;

    int f[n2];

    cout<<"enter the final states"<<"\n";
    for(int j=0; j<n2; j++)cin>>f[j];

    int n=n1+n2;
    int dfa[n][2];

    cout<<"enter the DFA table"<<"\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<2; j++)
        {
            cin>>dfa[i][j];
        }

    char arr[n][n];

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)arr[i][j]='z';



    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)arr[i][j]='*';

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            int flag1=-1,flag=-1;
            for(int track=0; track<n1; track++)
            {
                if(nf[track]==i)flag1=0;
            }

            for(int track=0; track<n1; track++)
            {
                if(nf[track]==j)flag=0;
            }

            if(flag1==0&&flag==0)arr[i][j]='e';

            flag1=-1;
            flag=-1;
            for(int track=0; track<n2; track++)
            {
                if(f[track]==i)flag1=0;
            }

            for(int track=0; track<n2; track++)
            {
                if(f[track]==j)flag=0;
            }

            if(flag1==0&&flag==0)arr[i][j]='e';






        }



    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {

            if(arr[i][j]=='e')
            {

                int temp1,temp2;

                temp1=dfa[i][0];

                temp2=dfa[j][0];

                if(arr[temp1][temp2]=='*'||arr[temp2][temp1]=='*')
                {
                    arr[i][j]='*';



                }

                temp1=dfa[i][1];
                temp2=dfa[j][1];

                if(arr[temp1][temp2]=='*'||arr[temp2][temp1]=='*')arr[i][j]='*';

                for(int i=0; i<n; i++)
                    for(int j=0; j<i; j++)
                    {

                        if(arr[i][j]=='e')
                        {

                            int temp1,temp2;

                            temp1=dfa[i][0];

                            temp2=dfa[j][0];

                            if(arr[temp1][temp2]=='*'||arr[temp2][temp1]=='*')
                            {
                                arr[i][j]='*';



                            }

                            temp1=dfa[i][1];
                            temp2=dfa[j][1];

                            if(arr[temp1][temp2]=='*'||arr[temp2][temp1]=='*')arr[i][j]='*';



                        }





                    }




            }
        }

    //cout<<"\n"<<the table is:"<<;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {

            //if(arr[i][j]=='*')
            //{

            cout<<arr[i][j]<<"|";



            //}




        }

        cout<<"\n";


    }

    cout<<"\n\n\n";


    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {

            if(arr[i][j]=='e')
            {

                cout<<"equivalent states:"<<i<<"&"<<j<<"\n";



            }




        }















}

