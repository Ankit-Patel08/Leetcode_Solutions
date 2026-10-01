#include<bits/stdc++.h>
using namespace std;

int main(){
    int vertex, edges;
    cin>>vertex>>edges;

    vector<vector<int>>AdjMat(vertex,vector<int>(vertex,0));
    for(int i = 0; i<edges; i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight;
    }
    for(int i = 0;i<vertex; i++){
        for(int j = 0;j<vertex; j++){
            cout<<AdjMat[i][j]<<"   ";
        }
        cout<<endl;
    }
}