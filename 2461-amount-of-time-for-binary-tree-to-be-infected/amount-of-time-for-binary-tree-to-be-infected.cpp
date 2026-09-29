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

    void constructAdj(TreeNode* root , unordered_map<int , vector<int>>& adj){
        if(!root) return;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        constructAdj(root->left , adj);
        constructAdj(root->right , adj);
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        unordered_map<int , vector<int>>adj;

        constructAdj(root , adj);

        int time = -1;

        queue<int>q;
        q.push(start);

        unordered_set<int>vis;

        vis.insert(start);

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int node = q.front();
                q.pop();

                for(auto& nei : adj[node]){
                    if(!vis.count(nei)){
                        q.push(nei);
                        vis.insert(nei);
                    }
                }
            }
            time++;
        }
        return time;
    }
};