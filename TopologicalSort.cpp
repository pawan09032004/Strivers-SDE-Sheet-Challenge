#include <bits/stdc++.h>
void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs(it, adj, vis, st);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{

    vector<int> adj[v];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
