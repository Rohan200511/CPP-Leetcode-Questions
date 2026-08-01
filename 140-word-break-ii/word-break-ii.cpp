class Solution {
public:
    int n;
    unordered_set<string>st;
    vector<string>ans;

    void solve(string& s , string curr , int i){
        if(i >= n){
            ans.push_back(curr);
            return;
        }

        for(int j = i ; j < n ; j++){
            string ori = curr;
            string temp = s.substr(i , j - i + 1);

            if(st.count(temp)){
                if(!curr.empty()) curr += " ";

                curr += temp;
                solve(s , curr , j + 1);
            }
            curr = ori;
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(string& word : wordDict) st.insert(word);

        string curr = "";

        solve(s , curr , 0);

        return ans;
    }
};