#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    vector<int>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //u--->v  sc-directed:O(E)  undirected:O(2E)
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    return 0;
}