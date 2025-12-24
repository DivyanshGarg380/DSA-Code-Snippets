#include <bits/stdc++.h>
using namespace std;

/*
    BFS Approach
*/

bool detect(int src, vector<int> adj[], int vis[]){
	vis[src] = 1;
	queue<pair<int, int>>q;
	q.push({src, -1});
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto adjNode: adj[node]){
			if(!vis[adjNode]){
				vis[adjNode] = 1;
				q.push({adjNode, node});
			}
			else if(parent != adjNode){
				return true; // cylce found
			}
		}
	}
	return false;
}

bool isCycle(int V, vector<int> adj[]){
	// Code here
	int visited[V] = {0};
	for(int i = 0; i < V; i++){
		if(!visited[i]){
			if(detect(i, adj, visited)) return true;
		}
	}
	return false;
}

// TC: O(V + E)
// SC: O(V)

/*
    DFS Approach
*/

bool dfs(int node, int parent, vector<int> adj[], int vis[]){
    vis[node] = 1;
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(dfs(adjNode, node, adj, vis)) return true;
        }
        else if(adjNode != parent){
            return true; // cycle found
        }
    }
    return false;
}

bool isCycleDFS(int V, vector<int> adj[]){
    int visited[V] = {0};
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

// TC: O(V + E)
// SC: O(V)


