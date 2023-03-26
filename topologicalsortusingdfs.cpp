#include<bits/stdc++.h>

void toposort(int node, vector<int> &visited,  stack<int>&s , unordered_map<int,list<int>> &adj)
{
    
    visited[node]=1;
    for(auto i: adj[node]){
        if(!visited[i]){
          toposort(i,visited,s,adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges,int n, int e)
{
    // prepare adjlist
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v= edges[i][1];
        
        adj[u].push_back(v);
        
    }
    
    vector<int> ans;
    vector<int> visited(n,0);
    stack<int> s;

    for(int i=0; i<n;i++){
        if(!visited[i]){
            toposort(i,visited,s,adj);
            
        }
    }

    while(!s.empty())
    
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}