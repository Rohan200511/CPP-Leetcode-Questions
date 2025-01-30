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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        ans.push_back(root->val);
        vector<int>leftsubtree=preorderTraversal(root->left);
        vector<int>rightsubtree=preorderTraversal(root->right);
        ans.insert(ans.end(), leftsubtree.begin(), leftsubtree.end());
        ans.insert(ans.end(), rightsubtree.begin(), rightsubtree.end());
        return ans;
    }
};