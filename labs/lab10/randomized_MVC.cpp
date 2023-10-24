#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main(){

    int n;
    cout << "Enter number of vertices : \n";
    cin >> n;

    int e;
    cout << "Enter number of edges : \n";
    cin >> e;

    cout << "Enter edges : \n";
    vector<vector<int>> adj(n,vector<int>());
    map<pair<int,int>,int> mp;
    vector<pair<int,int>> vp;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}] = 1;
        vp.push_back({u,v});
    }
    
    // ---------------------- Algo starts ------------------------------
    set<int> mvc;
    while(mp.size()){
        srand(time(0));
        int random_edge = rand() % e;
        auto edge = vp[random_edge];
        if(mp.find(edge) != mp.end()){
            int u = edge.ff;
            int v = edge.ss;
            mvc.insert(u);
            mvc.insert(v);
            mp.erase({u,v});
            mp.erase({v,u});
            for(auto i : adj[u]){
                mp.erase({u,i});
                mp.erase({i,u});
            }
            for(auto i : adj[v]){
                mp.erase({v,i});
                mp.erase({i,v});
            }
        }
    }
    
    for(auto i : mvc){
        cout << i << " ";
    }
    // ------------------------ Algo ends ------------------------------


    return 0;
}