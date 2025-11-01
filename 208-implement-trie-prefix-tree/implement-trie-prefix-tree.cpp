class Trie {
public:
    struct TrieNode{
        bool isEndofWord;
        TrieNode* children[26];
    };

    TrieNode* getNode(){
        TrieNode* newNode = new TrieNode();
        newNode->isEndofWord = false;
        for(int i = 0 ; i < 26 ; i++){
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    TrieNode* root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            int indx = ch - 'a';
            if(!crawl->children[indx])
                crawl->children[indx] = getNode();
            crawl = crawl->children[indx];
        }
        crawl->isEndofWord = true;
    }
    
    bool search(string word) {
        TrieNode* crawl = root;
        for(char ch : word){
            int indx = ch - 'a';
            if(!crawl->children[indx])
                return false;
            crawl = crawl->children[indx];
        }
        return crawl->isEndofWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawl = root;
        for(char ch : prefix){
            int indx = ch - 'a';
            if(!crawl->children[indx])
                return false;
            crawl = crawl->children[indx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */