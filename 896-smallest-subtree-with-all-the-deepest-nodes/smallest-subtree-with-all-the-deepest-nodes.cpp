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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr;

        unordered_map<TreeNode* , TreeNode*>parent;
        queue<pair<TreeNode* , int>>q;

        q.push({root , 0});
        parent[root] = nullptr;

        int maxLevel = 0;
        vector<TreeNode*> deepest;

        while(!q.empty()){
            auto [node , level] = q.front();
            q.pop();

            if(level > maxLevel){
                maxLevel = level;
                deepest.clear();
                deepest.push_back(node);
            }
            else if(level == maxLevel){
                deepest.push_back(node);
            }
            if(node->left){
                parent[node->left] = node;
                q.push({node->left , level + 1});
            }

            if(node->right){
                parent[node->right] = node;
                q.push({node->right , level + 1});
            }
        }

        while(deepest.size() > 1){
            unordered_set<TreeNode*>s;

            for (auto* node : deepest) {
                s.insert(parent[node]);
            }
            deepest.assign(s.begin(), s.end());
        }

        return deepest[0];
    }
};