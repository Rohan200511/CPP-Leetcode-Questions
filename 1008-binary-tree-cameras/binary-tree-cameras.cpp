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
    //0 covered 1camera -1needs
    int cnt = 0;

    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == -1 || right == -1){
            cnt++;
            return 1;
        }

        else if(left == 1 || right == 1) return 0;

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if (!root) return 0;

        int state = dfs(root);

        if (state == -1) {
            cnt++;
        }

        return cnt;
    }
};