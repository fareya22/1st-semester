#include<bits/stdc++.h>
#include "makecfg.cpp"
using namespace std;

void dfs_visit(int a,int b);
//int graph[100][100];
char color[100];
int discovery_time[100];
int finishing_time[100];
int parent[100];
int path[100];
int times;
vector<vector<int>> matrix(totalLine, vector<int>(totalLine, 0));
struct Node
 {
    int data;
    Node* next;
    Node*previous;
};

Node* createNode(int data)
 {
   Node* newNode = new Node();
   newNode->data = data;
   newNode->next = nullptr;
   return newNode;
}


void addEdge(vector<Node*>& adjList, int src, int dest)
 {
  Node* newNode = createNode(dest);
  newNode->next = adjList[src];
  adjList[src] = newNode;
}


void createAdjacencyList(const vector<vector<int>>& matrix, vector<Node*>& adjList)
 {
    int numNodes = matrix.size();
     adjList.resize(numNodes, nullptr);

   for (int i = 0; i < numNodes; ++i)
    {
       for (int j = 0; j < numNodes; ++j)
        {
                 if (matrix[i][j] == 1)
                  {
                      addEdge(adjList, i+1, j+1);
                  }
       }
   }
}



void make_graph()
//int main()
{
               cfg();


  analyze(1, totalLine);
  edgeCreating(1, totalLine);

  int maxNodes = totalLine;
  //vector<vector<int>> matrix(maxNodes, vector<int>(maxNodes, 0));
 /*int matrix[maxNodes][maxNodes];
  for(int i=0;i<maxNodes;i++)
  {
      for(int j=0;j<maxNodes;j++)
      {
          matrix[i][j]= 0;
      }
  }*/

  for (int i = 1; i <= maxNodes; ++i)
    {
       for (int j = 0; j < edge[i].size(); ++j)
    {
          int dest = edge[i][j];
           matrix[i - 1][dest - 1] = 1;
    }
  }


  cout << "The adjacency matrix representing the graph:\n";
  for (int i = 0; i < maxNodes; ++i)
    {
      for (int j = 0; j < maxNodes; ++j)
       {
            cout << matrix[i][j] << " ";
      }
        cout << endl;
  }
  vector<Node*> adjList;
  createAdjacencyList(matrix, adjList);

  cout << "The adjacency list representing the graph:\n";
  for (int i = 0; i < adjList.size(); ++i)
    {
       cout << i << "->";
        Node* currentNode = adjList[i];
       while (currentNode != nullptr)
           {
                cout << currentNode->data << " ";
                 currentNode = currentNode->next;
            }
       cout << endl;
  }

    /*for(int i=0;i<=maxNodes;i++)
    {
        for(int j=0;j<=maxNodes;j++)
        {
            g[i][j]=matrix[i][j];
        }
    }

     for(int i=0;i<=maxNodes;i++)
    {
        for(int j=0;j<=maxNodes;j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }*/
  for (Node* node : adjList)
{
    Node* current = node;
    while (current != nullptr)
    {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }

}

void dfs(int ver,int source){

     for(int i=1;i<=ver;i++){
        color[i]='W';
        discovery_time[i]=INT_MAX;
        finishing_time[i]=INT_MAX;
        parent[i]=-1;
     }
     dfs_visit(ver,source);
     for(int i=1;i<=ver;i++){
        if(color[i]=='W'){
            dfs_visit(ver,i);
        }
     }
     for(int i=1;i<=ver;i++){
        printf("Parent of %d is: %d\n",i,parent[i]);
        printf("Discovery time of %d is: %d\n",i,discovery_time[i]);
        printf("Finishing time of %d is: %d\n",i,finishing_time[i]);
     }

}

void dfs_visit(int ver,int u){

    color[u]='G';
    times++;
    discovery_time[u]=times;

      for(int j=1;j<=ver;j++){

         if(matrix[u][j]==1 && color[j]=='W'){
            parent[j]=u;
            path[j]=path[u]+1;
            dfs_visit(ver,j);
         }
      }
      color[u]='B';
      times++;
      finishing_time[u]=times;

}

int main()
{
    make_graph();
    dfs(totalLine,1);
}






