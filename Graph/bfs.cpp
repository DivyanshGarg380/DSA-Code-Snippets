#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class graph {
 public :
 int node ;
 vector<vector<int>>adj_mtx;
 graph(int n ){
 node = n ;
 adj_mtx = vector<vector<int>>(n , vector<int>(n , 0));
 }
 void add_edge ( int v1 , int v2 ){
 adj_mtx[v1][v2]=1;
 adj_mtx[v2][v1]=1;
 }
 void bfs ( int first_vtx ){
 vector<bool> track_visited(node , false);
 track_visited[first_vtx]=true;
 queue<int>q;
 q.push(first_vtx);

 while(!q.empty()){
 int current = q.front();
 cout<<"Vertex : "<<current<<endl;
 q.pop();
 for(int i = 0 ; i < node ; i++){
 if(adj_mtx[current][i]==1 && track_visited[i] != true){
 q.push(i);
 track_visited[i]=true;
 }
 }
 }
 }
};
int main(){

 graph g1(5);
 g1.add_edge(0,1);
 g1.add_edge(0,3);
 g1.add_edge(1,2);
 g1.add_edge(2,3);
 g1.add_edge(2,4);
 g1.bfs(0);

 return 0 ;
}