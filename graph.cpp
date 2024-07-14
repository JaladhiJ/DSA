#include<unordered_map>
#include<vector>
#include<iostream>
#include<utility>
#include<queue>
#include<set>
using namespace std;

// Implement a node struct if you feel 
// struct node{
//   int value;
//   vector<node*> roads;
//   node(int val)
//   {
//     value=val;
//   }
// };

// Implement the graph class
class Graph
{
  // vector<node*> roadnet;
  public:
  int no_of_vertices;
  vector<pair<int,int> > edges;
        Graph(int no_of_vertices, vector<pair<int,int> > edges){
          this->no_of_vertices=no_of_vertices;
          this->edges=edges;
          return;
        };
        vector<int> getneighbours(int v){
          vector<int>neighbours;
          for(int i=0;i<edges.size();i++)
          {
            if(edges[i].first==v)
            {
              neighbours.push_back(edges[i].second);
            }
            if(edges[i].second==v)
            {
              neighbours.push_back(edges[i].first);
            }
          }
        return neighbours;
        };
};


void bfs(Graph g, int source,unordered_map<int, int>& parent)
{
  queue<int> q;
  set<int> visited;
  visited.insert(source);
  q.push(source);
  while(!q.empty())
  {
    int v=q.front();
    q.pop();
    vector<int>neighbours=g.getneighbours(v);
    for(int i=0;i<neighbours.size();i++)
    {
      if(visited.count(neighbours[i])==0)
      {
        visited.insert(neighbours[i]);
        q.push(neighbours[i]);
        parent[neighbours[i]]=v;
      }
    }
  }
  parent[source]=-1;
  return;
};

