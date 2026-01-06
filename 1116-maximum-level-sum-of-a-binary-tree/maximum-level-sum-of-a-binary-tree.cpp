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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        priority_queue<pair<int,int>>pq;
        q.push({root , 1});

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            int level = q.front().second;
            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front().first;
                q.pop();

                sum += curr->val;

                if(curr->left)q.push({curr->left , level+1});
                if(curr->right)q.push({curr->right , level+1});
            }
            pq.push({sum , -level});
        }

        return -pq.top().second;
    }
};