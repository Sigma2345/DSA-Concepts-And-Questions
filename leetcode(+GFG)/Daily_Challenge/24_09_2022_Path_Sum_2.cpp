//  https://leetcode.com/problems/path-sum-ii/

/*
    we travel all paths from root to leaf and check if the sum is 0 
    by subtracting the value of each node from target sum 
    
    if at leaf node we find that node->val = sum required then we push the entire path 
    to the vector of vectors . 
*/

class Solution {
public:
    vector<vector<int>> ans ; 
    void Solve(TreeNode*root , int k , vector<int> ans1 ){
        if(root==NULL){
            return  ; 
        }
        ans1.push_back(root->val) ; 
        if(root->val==k && !root->left && !root->right){
            ans.push_back(ans1) ;  
            return ; 
        }
        Solve(root->left , k - root->val ,  ans1) ;
        Solve(root->right , k - root->val  , ans1) ; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root ) return ans ;
        vector<int> ans1 ; 
        Solve(root , targetSum , ans1 ) ; 
        return ans ;
    }
};
