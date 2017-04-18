/*..................................
.....@ Vivek Ranjan ................
..................................*/

//Graph implementation using vector(undirected and unweighted graph)
#include <bits/stdc++.h>
using namespace std;
int visited[100000];
int vis[10000];
void addEdge(vector <int> adj[],int u,int v);
void printAdjList(vector <int> adj[],int n);
void dfs(vector <int> adj[],int u);
void bfs(vector <int> adj[],int source);

int main(){
	//here nodes are marked from 0 to (n-1)
	cout << "Enter the number of nodes and number of edges" << endl;
	int n,m;
	cin >> n >> m;
	memset(visited,0,sizeof visited);
	memset(vis,0,sizeof vis);
	vector <int> adj[n];
	cout << "Enter the edges" << endl;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		addEdge(adj,x,y);
	}
	printAdjList(adj,n);
	cout << "Using DFS, the graph is : ";
	for(int i=0;i<n;i++){
		if(visited[i]==0)
			dfs(adj,i);
	}
	cout << endl;
	cout << "Using BFS, the graph is : ";
	for(int i=0;i<n;i++){
		if(vis[i]==0)
			bfs(adj,i);
	}
	cout << endl;
	return 0;
}


//function to add edges in a graph
void addEdge(vector <int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}


//function to print adjacency list
void printAdjList(vector <int> adj[],int n){
	cout << "The Adjacency list is :" << endl;
	for(int i=0;i<n;i++){
		cout << i << " -> ";
		for(int j=0;j<adj[i].size();j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}


//DFS function
void dfs(vector <int> adj[],int u){
	visited[u] = 1;
	cout << u << " ";
	for(int i=0;i<adj[u].size();i++){
		if(visited[adj[u][i]]==0)
			dfs(adj,adj[u][i]);
	}
}


//BFS function
void bfs(vector <int> adj[],int source){
	queue <int> Q;
	Q.push(source);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		if(vis[v]==0){
			vis[v] = 1;
			cout << v << " ";
			for(int i=0;i<adj[v].size();i++){
				if(vis[adj[v][i]]==0){
					Q.push(adj[v][i]);
				}
			}
		}
	}
}