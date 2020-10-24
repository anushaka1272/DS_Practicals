#include<bits/stdc++.h>

using namespace std;

#include<vector>
#include<stack>

void dfs(int S,bool* visited,stack<int>& s,vector<int> adj[])//
{
    vector<int>::iterator i;
    for(i=adj[S].begin();i!=adj[S].end();i++)
    {
        if(!visited[*i])
        {
            visited[*i]=true;
            dfs(*i,visited,s,adj);
        }
    }
    s.push(S);
}

void dfsHelp(int S,bool* visited,vector<int> graph[])//
{
    vector<int>::iterator i;
    for(i=graph[S].begin();i!=graph[S].end();i++)
    {
        if(!visited[*i])
        {
            visited[*i]=true;
            dfsHelp(*i,visited,graph);
        }
    }
    visited[S]=true;
}

int kosaraju(int V, vector<int> adj[])
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    stack<int> s;//
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,s,adj);
        }
    }
    vector<int> graph[V];
    for(int x=0;x<V;x++)
    {
        vector<int>::iterator i;
        for(i=adj[x].begin();i!=adj[x].end();i++)
        {
            graph[*i].push_back(x);
        }
    }
    
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int count=0;
    while(!s.empty())
    {
        int S=s.top();
        s.pop();
        if(!visited[S])
        {
            dfsHelp(S,visited,graph);
            count++;
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}