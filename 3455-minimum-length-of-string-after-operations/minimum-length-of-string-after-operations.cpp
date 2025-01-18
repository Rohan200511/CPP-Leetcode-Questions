class Solution {
public:
    int minimumLength(string s) {
        int arr[26]={0};
        int l=s.length();
        for(int i=0;i<l;i++) arr[s[i]-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
            if(arr[i]%2==0) ans+=2;
            else ans+=1;
        }
        }
        return ans;
    }
};