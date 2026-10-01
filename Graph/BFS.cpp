#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes;
    cin>>nodes;
    int edge;
    cin>>edge;
    vector<int> adjli[nodes];
    for(int i = 0; i<edge; i++){
        int u,v;
        cin>>u>>v;
        adjli[u].push_back(v);
        adjli[v].push_back(u);
    }
    for(int i = 0; i<nodes; i++){
        cout<< i <<" -> ";
        for(int x : adjli[i]){
            cout<< x<<" ";
        }
        cout<<"\n";
    }

    queue<int>q;
    vector<int> visited(nodes, 0);
    vector<int> ans;
    q.push(0);
    visited[0] = 1;
    int ele;
    while(!q.empty()){
        ele = q.front();
        q.pop();
        ans.push_back(ele);

        for(auto x : adjli[ele]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
            }
        }
    }

    for(int i = 0; i<nodes; i++){
        cout<< ans[i]<<" ";
    }

}