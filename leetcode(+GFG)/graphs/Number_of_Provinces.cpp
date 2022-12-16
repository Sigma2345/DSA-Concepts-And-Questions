// https://leetcode.com/problems/number-of-provinces/

/*
    the approach is first to make a directed 
    graph adjacency list and cnt the number of times 
    DFS has to be run 

    -> while visiting each node mark vis[node] = true
    -> this is to check that node is not visited again 
*/

class Solution
{
public:
    void DFS(int src, vector<vector<int>> &h, vector<bool> &vis)
    {
        // base case
        //  if(vis[src]) return;
        vis[src] = true;
        for (auto x : h[src])
        {
            if (!vis[x])
                DFS(x, h, vis);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> h(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j])
                    h[i].push_back(j);
            }
        }
        int cnt = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                // cout<<"INDEX "<<i<<endl ;
                DFS(i, h, vis);
            }
        }
        return cnt;
    }
};
