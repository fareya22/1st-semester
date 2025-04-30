#include<bits/stdc++.h>
#include<stdlib.h>
#include <iostream>
#include "graph.cpp"
using namespace std;

void dfs_visit(int a,int b);
char color[100];
int discovery_time[100];
int finishing_time[100];
int parent[100];
int path[100];
int times;

void dfs(const vector<vector<int>>& matrix, int vertex, int source);
void dfs_visit(int graph[100][100], int vertex, int newSource);



int main()
{
    make_graph();
    dfs(matrix,totalLine,1);
}

void dfs(const vector<vector<int>>& matrix, int vertex, int source)
{
    for (int i = 1; i <= vertex; i++)
    {
        color[i] = 'W';
        discovery_time[i] = INT_MAX;
        finishing_time[i] = INT_MAX;
        parent[i] = -1;
    }

    // Convert 2D vector to 2D array
    int graph[100][100];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            graph[i][j] = matrix[i][j];
        }
    }
     cout<<"\n\n\n";
     for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }

    dfs_visit(graph, vertex, source);

    for(int i=1;i<=vertex;i++){
        if(color[i]=='W'){
            dfs_visit(graph, vertex,i);
        }
     }

    for (int i = 1; i <= vertex; i++)
    {
        cout << "Parent of " << i << " is: " << parent[i] <<endl;
        cout << "Discovery time of " << i << " is: " << discovery_time[i] <<endl;
        cout << "Finishing time of " << i << " is: " << finishing_time[i] << endl;
    }
}

void dfs_visit(int graph[100][100], int vertex, int newSource)
{
    color[newSource] = 'G';
    times++;
    discovery_time[newSource] = times;

    for (int j = 1; j <= vertex; j++)
    {
        if (graph[newSource][j] == 1 && color[j] == 'W')
        {
            parent[j] = newSource;
            path[j] = path[newSource] + 1;
            dfs_visit(graph, vertex, j);
        }
    }
    color[newSource] = 'B';
    times++;
    finishing_time[newSource] = times;
}






