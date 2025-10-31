
#include<iostream>
#include<vector>
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

 void dfs_util(int start, vector<bool>& track_visited) {
 track_visited[start] = true;
 cout << "Visited : " << start << endl;
 for (int i = 0; i < node; i++) {
 if (adj_mtx[start][i] == 1 && !track_visited[i]) {
 dfs_util(i, track_visited);
 }
 }
 }
 void dfs(int start) {
 vector<bool> track_visited(node, false);
 dfs_util(start, track_visited);
 }
};
int main(){
 
 graph g1(5);
 g1.add_edge(0,1);
 g1.add_edge(0,3);
 g1.add_edge(1,2);
 g1.add_edge(2,3);
 g1.add_edge(2,4);
 g1.dfs(0);
 return 0;
}