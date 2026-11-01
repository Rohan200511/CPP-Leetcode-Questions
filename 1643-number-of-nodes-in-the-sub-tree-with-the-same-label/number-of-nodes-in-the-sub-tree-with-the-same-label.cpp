class Solution {
public:

    unordered_map<int , vector<int>>adj;
    vector<int>ans;
    string labels;

    vector<int> dfs(int u , int par){
        vector<int>freq(26 , 0);

        freq[labels[u] - 'a']++;

        for(int v : adj[u]){
            if(v == par) continue;

            vector<int>child = dfs(v , u);

            for(int i = 0 ; i < 26 ; i++){
                freq[i] += child[i];
            }
        }

        ans[u] = freq[labels[u] - 'a'];

        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        ans.resize(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0 , -1);

        return ans;
    }
};