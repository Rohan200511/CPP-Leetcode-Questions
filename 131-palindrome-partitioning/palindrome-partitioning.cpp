class Solution {
public:     

    bool isPalindrome(string s , int start , int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void helper(string s , int n , vector<vector<string>>& ans , vector<string>& curr , int index){
        if(index == n){
            ans.push_back(curr);
            return;
        }

        for(int i = index ; i<n ; i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index , i-index+1));
                helper(s,n,ans,curr,i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string>curr;
        helper(s,n,ans,curr,0);
        return ans;
    }
};