/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
        
    bool isLeaf(Node* root){
        return root && root->left == nullptr && root->right == nullptr;
    }
    
    void collectLeft(Node* root , vector<int>& ans){
        if(!root) return;
        
        Node* curr = root;
        
        if(isLeaf(root)) return;
        
        ans.push_back(root->data);
        
        if(curr->left) collectLeft(curr->left , ans);
        else collectLeft(curr->right , ans);
    }
    
    void collectRight(Node* root , vector<int>& ans){
        if(!root) return;
        vector<int>temp;
        Node* curr = root;
        
        if(isLeaf(root)) return;
        
        temp.push_back(root->data);
        
        if(curr->right) collectRight(curr->right , ans);
        else collectRight(curr->left , ans);
        
        reverse(temp.begin() , temp.end());
        
        for (int x : temp) {
            ans.push_back(x);
        }
    }
    
    void addLeaves(Node* root, vector<int>& ans) {
        if (!root) return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    vector<int> boundaryTraversal(Node *root) {
        if (!root) return {};

        vector<int> ans;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        collectLeft(root->left, ans);
        addLeaves(root, ans);
        collectRight(root->right, ans);

        return ans;
    }
};