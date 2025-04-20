class Solution {
    private:
    bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
public:
   void recurse(int index, string& s, vector<string>& current, vector<vector<string>>& ans){
    if(index==s.length()){
        ans.push_back(current);
        return;
    }
    for(int i=index;i<s.length();i++){
        if(isPalindrome(s,index,i)){
            current.push_back(s.substr(index,i-index+1));
            recurse(i+1,s,current,ans);
            current.pop_back();
        }
    }
   }
 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>current;
        recurse(0,s,current,ans);
        return ans;
    }
};