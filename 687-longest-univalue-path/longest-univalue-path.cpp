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

    int ans = 0;

    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        if(root->left && root->val == root->left->val) left++;
        else left = 0;

        if(root->right && root->val == root->right->val) right++;
        else right = 0;

        ans = max(ans , left + right);
        
        return max(left , right);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }
};