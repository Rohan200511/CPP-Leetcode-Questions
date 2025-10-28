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

    int solve(TreeNode* root , int currS){
        if(!root) return 0;
        currS = currS*10 + root->val;

        if(!root->left && !root->right) return currS;

        int l = solve(root->left , currS);
        int r = solve(root->right , currS);

        return l + r;
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root , 0);
    }
};