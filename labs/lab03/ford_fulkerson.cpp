#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &residual, vector<int> &parent, int s, int t){
    int n = residual.size();
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int v = 0; v < n; v++){
            if(!vis[v] && residual[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                parent[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return false;
}

int ford_fulkerson(vector<vector<int>> &g, int s, int t){
    int n = g.size();
    vector<vector<int>> residual(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            residual[i][j] = g[i][j];
        }
    }
    
    int max_flow = 0;
    vector<int> parent(n, -1);
    while(bfs(residual,parent,s,t)){
        int bnc = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            bnc = min(bnc, residual[u][v]);
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            residual[u][v] -= bnc;
            residual[v][u] += bnc;
        }
        max_flow += bnc;
    }
    
    return max_flow;
}

int main() {
	// your code goes here
	
	
// 	vector<vector<int>> g = {
//     	{0,16,13,0,0,0},   
//     	{0,0,10,12,0,0},
//     	{0,4,0,0,14,0},
//     	{0,0,9,0,0,20},
//     	{0,0,0,7,0,4},
//     	{0,0,0,0,0,0}
// 	};
    int n;
    cout << "Enter Number of vertices : ";
    cin >> n;
    
    vector<vector<int>> g(n, vector<int> (n,0));
    
    int e;
    cout << "Enter Number of edges : ";
	cin >> e;
	
	cout << "Enter edges with their weights : ";
	for(int i = 0; i < e; i++){
	    int u, v, w;
	    cin >> u >> v >> w;
	    g[u][v] = w;
	}
	
	int s = 0, t = n-1;
	int max_flow = ford_fulkerson(g,s,t);
	cout << "Max_flow is : " <<  max_flow << endl;
	return 0;
}
