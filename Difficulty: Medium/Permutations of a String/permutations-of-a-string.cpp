class Solution {
  public:
  
    void getPerm(string &s , int indx , set<string>& ans){
        if(indx == s.length()){
            ans.insert(s);
            return;
        }
        
        for(int i = indx ; i<s.length();i++){
            swap(s[i] , s[indx]);
            getPerm(s,indx+1,ans);
            swap(s[i] , s[indx]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> ans;
        getPerm(s,0,ans);
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};
