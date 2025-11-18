/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/


#include <stdio.h>
#include <stdlib.h>

int adj[10][10]; // assuming max 10 nodes.
int n;
// Initializing the Adjacency Matrix :o
void intiGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
}
// Adding Edge
void addEdge(int u,int v,int directed) {
    adj[u][v]=1; // For Directed because it only follows 1 way connection
    if(!directed) adj[v][u]=1; // undirected
}
// Displaying the Adjaceny Matrix
void displayGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
// Directed = 1 ( for Directed Graph) and viceversa 
struct Node{
    int vertex; // means the position number
    struct Node* next;
}Node;

struct Node* adjList[10]; // Adjancency List

// Adding Edges in the List
void addEdgeList(int u,int v,int directed){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode; // because we always insert at the head
    // For Undirected Graph -> 2 way connection important here
    if(!directed){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}
// Displaying Adjacency List
void displayList(int n){
    for(int i=0;i<n;i++){
        printf("%d: ",i);
        struct Node* temp = adjList[i];
        while(temp){
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
// BFS using adjacency Matrix
void BFS(int start){
    int visited[10] = {0};
    int queue[10], front = 0, rear = 0; // Queue stores the Node's index
    visited[start] = 1;
    queue[rear++] = start; 
    while(front < rear){
        int u = queue[front++];
        printf("%d ",u);
        for(int v=0; v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    // TC: O(n^2) , SC: O(n)
   // Can be optimized with Adjacency List
}
// DFS using Adjacency Matrix
void DFS(int start){
    int visited[10] = {0};
    DFSHelper(start,visited);
    printf("\n");
}
void DFSHelper(int u,int visited[]){
    visited[u] = 1;
    printf("%d ",u);
    for(int v=0;v<n;v++){
        if(adj[u][v] && !visited[v]){
            DFSHelper(v,visited);
        }
    }
    // TC: O(n^2) , SC: O(n); 
   // Can be optimized with Adjacency List
}
// Detecting Cycle in Undirected Graph using DFS
int cycleUndirectedGraphHelperFunc(int u, int visited[], int parent){
    visited[u] = 1;
    for(int v=0;v<n;v++){
        if(adj[u][v]){
            if(!visited[v]){
                if(cycleUndirectedGraphHelperFunc(v,visited,u)) return 1;
            }else if(v!=parent) return 1;
        }
    }
    return 0;
}
int cycleUnidirected(){
    int visited[10] = {0};
    for(int i=0;i<n;i++){
        if(!visited[i] && cycleUndirectedGraphHelperFunc(i,visited,-1))
            return 1;
    }
    return 0;
}
// Detecting Cycle in Directed Graph --> Use Recursion Stack 
// Recursion Stack -> keeps track of nodes currently in the DFS path.
int cycleDirectGraphHelperFunc(int u, int visited[], int recStack[]){
    visited[u] = 1;
    recStack[u] = 1;
    for(int v=0;v<n;v++){
        if(adj[u][v]){
            if(!visited[v] && cycleDirectGraphHelperFunc(v,visited,recStack))
                return 1;
            else if(recStack[v]) return 1;
        }
    }
    recStack[u] = 0;
    return 0;
}
int cycleDirected(){
    int visited[10] = {0}, recStack[10] = {0};
    for(int i=0;i<n;i++){
        if(!visited[i] && cycleDirectGraphHelperFunc(i,visited,recStack));
            return 1;
    }
    return 0;
}
// Checking if a graph is Bipartite using BFS
int isBipartite(){
    int color[10];
    for(int i=0;i<n;i++) color[i]=-1; // -1 = uncolored
    int queue[10],front=0,rear=0;
    
    for(int start=0;start<n;start++){
        if(color[start]!=-1) continue;
        color[start]=0;
        queue[rear++]=start;

        while(front<rear){
            int u=queue[front++];
            for(int v=0;v<n;v++){
                if(adj[u][v]){
                    if(color[v]==-1){
                        color[v]=1-color[u];
                        queue[rear++]=v;
                    } else if(color[v]==color[u]) return 0; // not bipartite
                }
            }
        }
    }
    return 1;
}
// BFS using Adjacency List
void BFS(int start){
    int visited[10] = {0};
    int queue[10] , front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear){
        int u = queue[front++];
        printf("%d ",u);
        struct Node* temp = adjList[u];
        while(temp!=NULL){
            int v = temp->vertex;
            if(!visited[v]){
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    // TC: O(vertices(n) + edges(e)) , SC: O(n) -> visited + queue
}
// DFS using Adjacency List --> Recursive :(
void DFSHelperFunc(int u, int visited[]){
    visited[u] = 1;
    printf("%d ",u);
    struct Node* temp = adjList[u];
    while(temp!=NULL){
        int v = temp->vertex;
        if(!visited[v]){
            visited[v] = 1;
            DFSHelperFunc(v,visited);
        }
        temp = temp->next;
    }
}
void DFS(int start, int n){
    int visited[10] = {0};
    DFSHelperFunc(start,visited);
    printf("\n");
    // TC: O(vertices(n) + edges(e)) , SC: O(n) -> visited + recursion stack
}
// Finding Degree of a Node 
// Undirected: count "Valid" edges in row of adjacency matrix.
// Directed: in-degree = count in column, out-degree = count in row.
int outDegree(int u){
    int count = 0;
    for(int v=0;v<n;v++){
        if(adj[u][v]) count++;
    }
    return count;
}
int inDegree(int u){
    int count = 0;
    for(int v=0;v<n;v++){
        if(adj[v][u]) count++; // condition reversed here
    }
    return;
}
// Count total Edges -> if Undirected then divide by 2 . Directed = count Edges
int countEdges(){
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(adj[i][j]) total++;
        }
    }
    return total;
}
// Connected Components (Undirected Graph)
// Just add this line in the condition when you check if(!visited[i])
// after calling DFSHelperFunc(i,visited) function. add component++;

// Finding Self Loop in a graph
int selfLoop(){
    for(int i=0;i<n;i++){
        if(adj[i][i]) return 1;
    }
    return 0;
}
// Finding Isolated Nodes -> Degree 0
void IsolatedDegree(){
    for(int i=0;i<n;i++){
        int degree = 0;
        for(int j=0;j<n;j++){
            if(adj[i][j]) degree++;
        }
        if(degree == 0) printf("Node %d is Isolated :(",i);
    }
}
// Check Connectivity -> Can you go from Node A to Node B ?
int isConnected(int start, int target){
    int visited[10] = {0};
    DFSHelperFunc(start,visited); // Call DFS
    return visited[target]; // Returns 1 or 0 depending if its visited or not
}
// Shortest Path in an Unweighted Graph -> Use BFS to avoid recursion :)
int shortestDistance(int start){
    int visited[10] = {0}, dist[10];
    for(int i=0;i<n;i++) dist[i] = -1;
    int queue[10] , front = 0, rear = 0;
    queue[rear++] = start, visited[start] = 1; dist[start] = 0;
    while(front < rear){
        int u = queue[front++];
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("Distance from %d to %d = %d\n", start, i, dist[i]);
    }
}
// Printing Nodes Reachable from a given Node -> Use BFS/DFS
void reachableNodes(int start){
    int visited[10] = {0};
     DFSHelperFunc(start,visited); // Call DFS or call BFS.
     printf("Nodes reachable from %d: ",start);
     for(int i=0;i<n;i++){
        if(visited[i]) printf("%d ",i);
     }
}
int main(){
    // Insert your example inputs here to test this program
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
// I track record my submissions, any usage of my solutions during contest can lead to dropping of your ratings. Beware 😈


