/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(!root) return ans;
        
        queue<pair<Node* , int>>q;
        
        q.push({root , 0});
        map<int,int>mp;
        
        while(!q.empty()){
            Node* curr = q.front().first;
            int currDist = q.front().second;
            q.pop();
            if(mp.find(currDist) == mp.end()) mp[currDist] = curr->data;
            
            if(curr->left) q.push({curr->left , currDist-1});
            if(curr->right) q.push({curr->right , currDist+1});
        }
        
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};