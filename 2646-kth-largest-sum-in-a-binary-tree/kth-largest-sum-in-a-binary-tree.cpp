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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root || k <= 0) return 0;
        vector<unsigned long long int>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            unsigned long long int sum = 0;
            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(sum);
        }
        sort(ans.rbegin(), ans.rend());
        if (k > ans.size()) return -1;

        return static_cast<long long>(ans[k - 1]);
    }
};