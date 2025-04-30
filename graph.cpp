#include<bits/stdc++.h>
#include "makecfg.cpp"
using namespace std;


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

void addEdge(vector<Node*>& adjList, int src, int dest);
void createAdjacencyList(const vector<vector<int>>& matrix, vector<Node*>& adjList);

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
  edgeCreating(mainStartLine,1, totalLine);

  int maxNodes = totalLine;
 vector<vector<int>> matrix(maxNodes, vector<int>(maxNodes, 0));
  vector<Node*> adjList;

    for (int i = 1; i <= maxNodes; ++i)
    {
       for (int j = 0; j < edge[i].size(); ++j)
     {
          int currentVal = edge[i][j];
           matrix[i - 1][currentVal - 1] = 1;
      }
   }

     createAdjacencyList(matrix, adjList);

  cout << "\t\t\tThe adjacency list representing the graph:\n\n";
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

  cout << "\t\t\tThe adjacency matrix representing the graph:\n\n\n";
  for (int i = 0; i < maxNodes; ++i)
    {
      for (int j = 0; j < maxNodes; ++j)
       {
            cout << matrix[i][j] << " ";
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
    }
  for (Node* node : adjList)
{
    Node* current = node;
    while (current != nullptr)
    {
      Node* next = current->next;
      delete current;
      current = next;
    }
  }*/

}









