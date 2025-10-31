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

    void solve(TreeNode* root , int targetSum , int currSum , vector<int>& curr , vector<vector<int>>& ans){
        if(!root) return;

        currSum += root->val;
        curr.push_back(root->val);
        if(!root->left && !root->right && currSum == targetSum){
            ans.push_back(curr);
        }

        else{
            solve(root->left,targetSum,currSum,curr,ans);
            solve(root->right,targetSum,currSum,curr,ans);
        }

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr;
        vector<vector<int>> ans;
        solve(root,targetSum,0,curr,ans);
        return ans;
    }
};