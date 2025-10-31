#include<iostream>
#include <vector>
#include <queue>
int g[100][100];
using namespace std;
class Graph
{
public:
int V;
Graph(int vertices) { V = vertices; }
void addEdge(int src, int v, int wt)
{
g[src][v] = wt;
g[v][src] = wt;
}
void Prims(int src)
{
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,
int>>> pq;
vector<bool> mst(V, false);
pq.push(make_pair(0, src));
int ans = 0;
while (pq.size() > 0)
{
int u = pq.top().second;
int edgewt = pq.top().first;
pq.pop();
if (!mst[u])
{
mst[u] = true;
ans = ans + edgewt;
for (int i = 0; i < V; i++)
{
if (g[u][i] != 0 && !mst[i])
pq.push(make_pair(g[u][i], i));
}
}
}
cout << "The MST of given graph is: " << ans << endl;
}
};
int main()
{
Graph g1(5);
g1.addEdge(0, 1, 5);
g1.addEdge(1, 2, 6);
g1.addEdge(0, 2, 13);
g1.addEdge(1, 3, 20);
g1.addEdge(3, 4, 15);
g1.Prims(0);
return 0;
}