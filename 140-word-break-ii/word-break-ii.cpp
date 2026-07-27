class Solution {
public:

    int n;
    unordered_set<string>st;

    void solve(int i , string& s , vector<string>& result , string& currSentence){

        if(i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for(int j = i ; j < n ; j++){

            string tempWord = s.substr(i, j-i+1);

            if(st.find(tempWord) != st.end()) {
                string origSentence = currSentence;
                if(!currSentence.empty())
                    currSentence += " ";
                
                currSentence += tempWord;

                solve(j+1, s , result , currSentence);

                currSentence = origSentence;
                
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(string word : wordDict){
            st.insert(word);
        }

        vector<string>ans;

        string currSentence = "";

        solve(0 , s , ans , currSentence);

        return ans;
    }
};