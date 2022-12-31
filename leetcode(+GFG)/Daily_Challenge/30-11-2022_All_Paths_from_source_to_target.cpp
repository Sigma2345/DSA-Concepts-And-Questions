// https://leetcode.com/problems/all-paths-from-source-to-target/description/
#include<bits/stdc++.h>
using namespace std; 

class Solution
{
public:
    // prints path in reverse 
    vector<vector<int>> ans;
    void PrintPath(
        unordered_map<int, int> &parent,
        int des)
    {
        int x = des;
        vector<int> v;
        while (x != parent[x])
        {
            v.push_back(x);
            x = parent[x];
        }
        v.push_back(0);
        reverse(v.begin(), v.end());
        ans.push_back(v);
    }

    void DFS(
        int src, int des,
        unordered_map<int, bool> &visited,
        unordered_map<int, int> &parent,
        vector<vector<int>> &graph)
    {
        // updating parent vector to check for path 
        if (src == des)
        {
            PrintPath(parent, des);
            return;
        }

        for (auto node : graph[src])
        {
            if (!visited[node])
            {
                parent[node] = src;
                DFS(node, des, visited, parent, graph);
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        parent[0] = 0;
        DFS(0, graph.size() - 1, visited, parent, graph);
        return ans;
    }
};
