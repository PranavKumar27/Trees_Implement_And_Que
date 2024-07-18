#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>
#define INF INT_MAX

using namespace std;

class Graph
{
    int Nodes;
    vector<vector<pair<int,int>>> Adj;
public:
    Graph(){}
    Graph(int n)
    {
        Nodes = n;
        Adj.resize(Nodes);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    void print_v(vector<int> v)
    {
        for(auto values:v)
        {
            cout << values << ",";
        }
        cout << endl;
    }
    void DijkstraPQ(vector<int>& dist,int s)
    {
        cout << __FUNCTION__ << endl;
        priority_queue<pair<int,int>> pq;
        pq.push({0,s});
        dist[s] = 0;
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();

            for(auto adjacent:Adj[node])
            {
                int adjacentNode = adjacent.first;
                int adjacentWt = adjacent.second;
                if(dist[adjacentNode]>adjacentWt+wt)
                {
                    dist[adjacentNode] = wt+adjacentWt;
                    pq.push({dist[adjacentNode],adjacentNode});
                }
            }
        }
        print_v(dist);
    }

    void DijkstraSET(vector<int>dist,int s)
    {
        cout << __FUNCTION__ << endl;
        set<pair<int,int>> S;
        S.insert({0,s});
        dist[s]=0;

        while(!S.empty())
        {
            pair<int,int> p = *(S.begin());
            int wt = p.first;
            int node = p.second;
            S.erase({wt,node});

            for(auto adjacent:Adj[node])
            {
                int adjacentNode = adjacent.first;
                int adjacentWt = adjacent.second;

                if(dist[adjacentNode]>wt+adjacentWt)
                {
                    if(S.find({dist[adjacentNode],adjacentNode})!=S.end())
                    {
                        S.erase({dist[adjacentNode],adjacentNode});
                    }
                    dist[adjacentNode] = wt+adjacentWt;

                    S.insert({dist[adjacentNode],adjacentNode});
                }
            }
        }
        print_v(dist);
    }
};

int main()
{
    int n=6;
    Graph G(n);
    G.addEdge(0,1,2);
    G.addEdge(1,2,3);
    G.addEdge(1,5,4);
    G.addEdge(2,3,1); 
    G.addEdge(2,4,7);
    G.addEdge(4,3,8);
    G.addEdge(5,2,5);
    G.addEdge(5,4,7);

    vector<int> dist;
    dist.resize(n,INF);
    int s=0;
    G.DijkstraPQ(dist,s);

    vector<int> dist1;
    dist1.resize(n,INF);
    int s1=0;
    G.DijkstraSET(dist1,s1);

    return 0;
}
