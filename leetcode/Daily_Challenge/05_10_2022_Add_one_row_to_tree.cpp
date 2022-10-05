//  https://leetcode.com/problems/add-one-row-to-tree/




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
    
    void Solve(TreeNode*root, int val, int depth){
        //base case
        if(!root) return ;  // if root is NULL we cannot do anything but return 
        
        if(depth==1){
            TreeNode*n = new TreeNode(val); // node for left tree 
            TreeNode*n1 = new TreeNode(val); // node for right tree 
            
            n->left = root->left; // join left half of tree to left of n  
            root->left = n ; // now point root->left  to n 
            
            n1->right = root->right ; // similar as first but for right and n1
            root->right = n1 ;
            
            return ; 
        }
        
        
        //recursive case
        Solve(root->left, val, depth-1) ; // decrease depth as traverse down
        Solve(root->right, val, depth-1); 
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //base case according to question 
        if(depth==1){
            TreeNode*n = new TreeNode(val, root, NULL) ; 
            return n ; 
        }   
        
        Solve(root, val, depth-1); 
        return root ; 
    }
};
