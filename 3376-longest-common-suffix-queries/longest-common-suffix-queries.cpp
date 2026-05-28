class Solution {
public: 

    struct TrieNode{
        int idx;
        TrieNode* children[26];

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };

    TrieNode* getNode(int i){
        TrieNode* temp = new TrieNode();

        temp->idx = i;

        for(int i = 0 ; i < 26 ; i++){
            temp->children[i] = NULL;
        }

        return temp;
    }


    void insert(TrieNode* root , int i , vector<string>& wordsContainer){
        string word = wordsContainer[i];
        int n = word.size();

        for(int j = n - 1 ; j >= 0 ; j--){
            int ch_idx = word[j] - 'a';

            if(root->children[ch_idx] == NULL){
                root->children[ch_idx] = getNode(i);
            }
            root = root->children[ch_idx];

            if(wordsContainer[root->idx].size() > n){
                root->idx = i;
            }
        }
    }

    int search(TrieNode* root , string& query){
        int res = root->idx;
        int n = query.size();

        for(int i = n - 1 ; i >= 0 ; i--){
            char ch = query[i];
            int ch_idx = ch - 'a';

            root = root->children[ch_idx];

            if(root == NULL){
                return res;
            }

            res = root->idx;
        }
        return res;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        vector<int>ans(m);

        TrieNode* root = getNode(0);

        for(int i = 0 ; i < n ; i++){
            if(wordsContainer[root->idx].length() > wordsContainer[i].length()){
                root->idx = i;
            }

            insert(root , i , wordsContainer);
        }

        for(int j = 0 ; j < m ; j++){
            ans[j] = search(root , wordsQuery[j]);
        }

        delete root;

        return ans;
    }
};