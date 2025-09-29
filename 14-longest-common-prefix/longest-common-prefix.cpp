class Solution {
public:


    string commonPrefix(string a , string b){
        int n = min(a.length() , b.length());
        string ans = "";

        for(int i = 0 ; i < n ; i++){
            if(a[i] == b[i]) ans+=a[i];
            else break;
        }
        return ans;
    }

    string lcpRec(vector<string>& strs , int l , int r){
        if(l == r) return strs[l];
        int mid = (l + r) / 2;

        string left = lcpRec(strs,l,mid);
        string right = lcpRec(strs,mid+1,r);
        return commonPrefix(left , right);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
    return lcpRec(strs, 0, strs.size() - 1);
    }
};