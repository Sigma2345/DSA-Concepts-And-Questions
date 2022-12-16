// https://leetcode.com/problems/clone-graph/

/*
 2 mappings are needed
 -> vis map to check if the node is visited
 -> mp which gives one to one Correspondence for each node
*/

class Solution
{
public:
    unordered_map<Node *, bool> vis;
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (vis[node])
            return mp[node];
        Node *n = new Node(node->val);
        vis[node] = true;
        mp[node] = n;
        for (auto v : node->neighbors)
        {
            if (v != NULL && !vis[v])
            {
                // traverse each node 
                // if not visited DFS
                n->neighbors.push_back(cloneGraph(v));
            }
            else
            {
                // if visited then just push the node
                n->neighbors.push_back(mp[v]);
            }
        }
        return n;
    }
};
