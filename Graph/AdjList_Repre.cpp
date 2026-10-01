#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<int>>AdjMat(vertex);
    for(int i = 0; i<edges; i++){
        int u,v;
        cin>>u>>v;
        AdjMat[u].push_back(v);
        AdjMat[v].push_back(u);
    }
    for(int i = 0;i<vertex; i++){
        cout<<i<<"->";
        for(int j = 0;j<AdjMat[i].size(); j++){
            cout<<AdjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}