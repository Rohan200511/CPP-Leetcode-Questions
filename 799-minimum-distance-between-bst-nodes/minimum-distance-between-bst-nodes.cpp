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
    void inorderVector(TreeNode* root, vector<int>& inOrder) {
        if (root == NULL) return;

        inorderVector(root->left, inOrder);
        inOrder.push_back(root->val);
        inorderVector(root->right, inOrder);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> inOrder;
        inorderVector(root, inOrder);

        int mini = INT_MAX;
        for (int i = 1; i < inOrder.size(); i++) {
            mini = min(mini, abs(inOrder[i] - inOrder[i - 1]));
        }
        return mini;
    }
};