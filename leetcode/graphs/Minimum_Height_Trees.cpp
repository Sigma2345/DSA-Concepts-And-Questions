// https://leetcode.com/problems/minimum-height-trees/

/*the idea is that there cannot be more than 2 centroids
  in a tree  
  1  centroid for odd number of elements
  2  centroids for even number of elements 
  if there is a cycle then there can be more than 2 centroids
  but that won't be a tree
*/

//Approach
/*
    keep removing leaf nodes until only 2 nodes left
*/
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // keep removing leaf nodes until only one left
        //  use BFS
        if (n == 1)
        {
            return {0};
        }

        // Adjacency list
        vector<vector<int>> h(n);
        vector<int> deg(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            h[edges[i][0]].push_back(edges[i][1]);
            h[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++, deg[edges[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 1)
                q.push(i);
        }
        // remaining nodes
        int remNodes = n;
        while (remNodes > 2)
        {
            int s = q.size();
            remNodes -= s;
            for (int i = 0; i < s; i++)
            {
                int x = q.front();
                q.pop();
                for (int j : h[x])
                {
                    // trim nodes and decrease deg of each connected component to the node
                    deg[j]--;
                    if (deg[j] == 1)
                    {
                        q.push(j);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
