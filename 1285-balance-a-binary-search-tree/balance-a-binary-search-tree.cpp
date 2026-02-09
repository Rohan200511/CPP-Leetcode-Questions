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
    vector<int>arr;

    TreeNode* buildTree(int i , int j){
        if(i > j) return NULL;
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(i , mid - 1);
        root->right = buildTree(mid + 1 , j);

        return root;
    }

    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        inorder(root);

        return buildTree(0 , arr.size() - 1);
    }
};