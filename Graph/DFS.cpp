#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &visi, int node, vector<int> &ans){
    visi[node] = 1;
    ans.push_back(node);

    for(auto x : adj[node]){
        if( !visi[x]){
            dfs(adj, visi, x, ans);
        }
    }
}

int main(){
    int vertex;
    cin>>vertex;
    int edges;
    cin>>edges;
    vector<int> adjli[vertex];
    for(int i = 0; i<edges; i++){
        int u,v;
        cin>>u>>v;
        adjli[u].push_back(v);
    }
    vector<int> ans;
    vector<int> visi(vertex,0);
    int start = 0;
    dfs(adjli,visi, start, ans);

    for(auto x : ans ) cout<< x << " ";
}