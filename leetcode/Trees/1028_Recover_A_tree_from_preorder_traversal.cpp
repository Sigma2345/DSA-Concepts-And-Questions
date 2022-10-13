// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
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
    TreeNode*makeTree(string traversal, int &i, int maxDepth){
        if(i>=traversal.length()) return NULL ; 
        int dashCnt =  0 , j = i  ;
        // cnt the dashes
        while( i<traversal.length() && traversal[i]=='-') i++, dashCnt++ ; 
        if(dashCnt < maxDepth){
            // return to original index because this is not part of allocated tree
            i = j ; 
            return NULL ; 
        }
        int num = 0 ;
        // make the numbers
        while(i<traversal.length() && traversal[i]!='-'){
            num = num*10 + (traversal[i]-'0');
            i++ ;
        }
        // cout<<num<<endl ;
        TreeNode*root = new TreeNode(num) ;
        // first make left tree
        root->left = makeTree(traversal, i, dashCnt+1); 
        // then forward index gives right tree
        root->right = makeTree(traversal, i, dashCnt+1);
        return root ;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0; 
        return makeTree(traversal, i, 0); 
    }
};
