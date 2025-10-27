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

    int maxSum;

    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);

        int Below_ans = l + r + root->val;
        int only_One = max(l , r) + root->val;
        int root_Only = root->val;

        maxSum = max({maxSum , Below_ans , only_One , root_Only});
        return max(only_One , root_Only);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};