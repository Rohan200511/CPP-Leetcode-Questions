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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;     //Left->Right->root//
        if(!root) return ans;
        vector<int>leftsubtree=postorderTraversal(root->left);
        vector<int>rightsubtree=postorderTraversal(root->right);
        ans.insert(ans.end(),leftsubtree.begin(),leftsubtree.end());
        ans.insert(ans.end(),rightsubtree.begin(),rightsubtree.end());
        ans.push_back(root->val);
        return ans;
    }
};