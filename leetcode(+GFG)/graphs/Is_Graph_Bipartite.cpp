// https://leetcode.com/problems/is-graph-bipartite/

/*
    the idea is to make 2 sets
    -> in DFS
        if we find some element whuch is already visited
        we check that it should not belong to same set as its neighbors
*/

class Solution
{
public:
    bool ans = true;

    void DFS(int src, vector<vector<int>> &graph, vector<set<int>> &v, vector<bool> &vis, int m)
    {

        vis[src] = true;
        v[m].insert(src);

        for (auto x : graph[src])
        {
            // x needs to be part of v[1-m] set
            // src is part of v[m]
            // so check if visited node is assigned correct set or not 
            if (vis[x] && v[m].find(x) != v[m].end())
            {
                ans = false;
                return;
            }
            else if (!vis[x])
                DFS(x, graph, v, vis, 1 - m);
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<set<int>> v(2);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                DFS(i, graph, v, vis, 0);
            if (!ans)
                return false;
        }
        return true;
    }
};
