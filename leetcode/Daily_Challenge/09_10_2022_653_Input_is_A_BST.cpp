// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // inorder traversal of binary search tree
    void f(vector<int>&ans, TreeNode*root){
        if(!root) return ; 
        
        f(ans, root->left); 
        ans.push_back(root->val) ;
        f(ans, root->right); 
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        f(ans, root);
        // inorder traversal of BST is in ascending order
        // so 2 pointer then would work 
        int s= 0 , e = ans.size()-1 ; 
        while(s<e){
            int sum = ans[s] + ans[e] ; 
            if(sum==k) return true ;
            else if(sum<k) s++ ; // we need to increase the sum
            else e-- ; // need to decrease the sum
        }
        return false ;
    }
};
