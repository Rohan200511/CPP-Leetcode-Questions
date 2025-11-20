class Solution {
public:

    bool isPalindrome(string s , int st , int end){
        while(st < end){
            if(s[st++] != s[end--]) return false;
        }
        return true;
    }

    void recurse(string s  , int n , int index , vector<string>& curr , vector<vector<string>>& ans){
        if(index == n){
            ans.push_back(curr);
            return;
        }


        for(int i = index ; i < n ; i++){
            if(isPalindrome(s , index , i)){
                curr.push_back(s.substr(index , i - index + 1));
                recurse(s , n , i + 1 , curr , ans);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        vector<vector<string>>ans;
        vector<string>curr;
        recurse(s , s.length() , 0 , curr , ans);
        return ans;
    }
};