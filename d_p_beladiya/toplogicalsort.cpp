vector<int> order; //Stores the Topological Order

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{   
    queue<int> q;
    vector<int> indeg(n + 1, 0);
    for(int i = 1; i <= n; i++)
        for(auto &it:g[i])
            indeg[it]++;
    for(int i = 1; i <= n; i++)
    {
        if(!indeg[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto &v:g[u])
        {
            indeg[v]--;
            if(!indeg[v])
                q.push(v);
        }
    }
    return (order.size() == n);
}







/////////////////////








bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0), bfs;
        for (auto& e : prerequisites)
            G[e[1]].push_back(e[0]), degree[e[0]]++;
        for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        for (int i = 0; i < bfs.size(); ++i)
            for (int j: G[bfs[i]])
                if (--degree[j] == 0) bfs.push_back(j);
        return bfs.size() == n;
    }