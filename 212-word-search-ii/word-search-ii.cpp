class Solution {
public:
    vector<string>res;
    int m , n;
    struct TrieNode{
        bool isEndofWord;
        TrieNode* children[26];
        string word;
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isEndofWord = false;
        newNode->word = "";
        for(int i = 0 ; i < 26 ; i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    void insert(TrieNode* root , string& word){
        TrieNode* crawl = root;

        for(int i = 0 ; i < word.length() ; i++){
            int indx = word[i]-'a';
            if(!crawl->children[indx]) crawl->children[indx] = getNode();
            crawl = crawl->children[indx];
        }
        crawl->isEndofWord = true;
        crawl->word = word;
    }

    void findTrieWords(vector<vector<char>>& board , int i , int j , TrieNode* root){
        if(i < 0 || i >=m || j < 0 || j >= n) return;

        if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr) return;

        root = root->children[board[i][j] - 'a'];

        if(root->isEndofWord == true){
            res.push_back(root->word);
            root->isEndofWord = false;
        } 

        char temp = board[i][j];
        board[i][j] = '$';

        findTrieWords(board , i , j+1 , root);
        findTrieWords(board , i+1 , j , root);
        findTrieWords(board , i , j-1 , root);
        findTrieWords(board , i-1 , j , root);

        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        TrieNode* root = getNode();

        for(string& word : words){
            insert(root,word);
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                char ch = board[i][j];

                if(root->children[ch-'a'] != nullptr) findTrieWords(board , i , j ,root);
            }
        }
        return res;
    }
};