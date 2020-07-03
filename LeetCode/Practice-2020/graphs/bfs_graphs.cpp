// Program to print BFS traversal from a given 
// source vertex. BFS(int s) traverses vertices  
// reachable from s. 
#include<iostream> 
#include <list> 
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph
{
    int V; // No of vertices
    map<int, vector<int>> adj;
    
    public:
    Graph(int V);
    
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    //adj = 
}

void Graph::addEdge(int v, int w)
{
    if (this->adj.find(v) == this->adj.end())    
    {
        //auto vec = new vector<int>{w};
        this->adj.insert(pair<int, vector<int>>(v, vector<int>()));
    }
    
    this->adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    vector<bool> visited(this->adj.size(), false);
    
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    
    cout << "outside" ;
    while(!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        
        //for(auto vec: adj[front])
        //{
            for (auto element : adj[front])
            {
                if (!visited[element])
                {
                    visited[element] = true;
                    q.push(element);
                }
            }
        //}
    }
}

// Driver program to test methods of graph class 
int main() 
{ 
    cout << "hello";
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 
