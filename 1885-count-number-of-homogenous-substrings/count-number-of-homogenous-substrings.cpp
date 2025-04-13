class Solution {
public:
    int countHomogenous(string s) {
      if(s.length()==0) return 0;
      int mod=1e9+7;
      int ans=s.length();
      int cnt=1;
      for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            ans=(ans+cnt)%mod;
            cnt++;
        }
        else cnt=1;
      }  
      return ans;
    }
};