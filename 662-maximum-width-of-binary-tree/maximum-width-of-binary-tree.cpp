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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode* , unsigned long long int>>q;
        q.push({root , 0});

        int maxWidth = 0;

        while(!q.empty()){
            int size = q.size();
            unsigned long long int stIdx= q.front().second;
            unsigned long long int endIdx= q.back().second;

            maxWidth = max(maxWidth , (int)(endIdx - stIdx + 1));

            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front().first;
                unsigned long long int index = q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left , 2 * index + 1});
                if(curr->right) q.push({curr->right , 2 * index + 2});
            }
        }
        return maxWidth;
    }
};