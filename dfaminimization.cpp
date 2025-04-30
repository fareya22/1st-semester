#include<bits/stdc++.h>
using namespace std;

string DFA[100][3];
string FinalStates[100];
char matrix[100][100];


bool check_final(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(FinalStates[i] == str)
            return true;
    }
    return false;
}

int check_state(string str, int size)
{
    for(int i = 1; i <= size; i++)
    {
        if(DFA[i][0] == str)
            return i;
    }
    return -1;
}

void Equivalence(int numOfStates)
{
    for(int i = 1; i <= numOfStates; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(check_final(DFA[i][0], numOfStates) && !check_final(DFA[j][0], numOfStates))
            {
                matrix[i][j] ='X' ;
            }
            else if(!check_final(DFA[i][0], numOfStates) && check_final(DFA[j][0], numOfStates))
            {
               matrix[i][j] ='X' ;
            }
        }
    }

    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 1; i <= numOfStates; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(matrix[i][j]=='=')
                {
                    int row, col;
                    row = check_state(DFA[i][1],numOfStates);
                    col = check_state(DFA[j][1],numOfStates);
                    if(matrix[row][col] == 'X')
                    {
                        matrix[i][j] = 'X';
                        flag = true;
                    }
                    row = check_state(DFA[i][2],numOfStates);
                    col = check_state(DFA[j][2],numOfStates);
                    if(matrix[row][col] == 'X')
                    {
                        matrix[i][j] = 'X';
                        flag = true;
                    }
                }
            }
        }
    }
}


int main()
{
    int numOfStates;
    freopen("input1.txt","r",stdin);
    cin >> numOfStates;
    for(int i = 1; i <= numOfStates; i++)
    {
        cin >> DFA[i][0] >> DFA[i][1] >> DFA[i][2];
    }

    int numOfFinalstate;
    cin >> numOfFinalstate;
    for(int i = 1; i <= numOfFinalstate; i++)
    {
        cin >> FinalStates[i];
    }

    for(int i = 0; i <100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            matrix[i][j] = '=';
        }
    }

    Equivalence(numOfStates);

    cout << "Equivalent states : \n";
    bool flag = true;
    for(int i = 1; i <=numOfStates; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(matrix[i][j]=='=')
            {
                cout <<  DFA[i][0] <<" ~ " << DFA[j][0] << endl;
                flag = false;
            }
        }
    }
    if(flag)
    {
        cout << "No equivalent state found!\n";
    }

    for(int i=1 ;i<= numOfStates;i++)
    {   if(i!=1)
        cout<<DFA[i][0]<<"||"<<" ";
        for(int j=1;j<i;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<" ||";
    for(int i=1;i<numOfStates;i++)
    cout<<" "<<DFA[i][0];
    return 0;
}


