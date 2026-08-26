class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        string ans = "";
        int ones = 0;

        for(int right = 0 ; right < n ; right++){
            if(s[right] == '1') ones++;

            while(ones > k){
                if(s[left] == '1') ones--;

                left++;
            }

            if(ones == k){
                while(s[left] == '0') left++;

                string curr = s.substr(left , right - left + 1);

                if(ans.empty() || curr.size() < ans.size()) ans = curr;
                if(curr.size() == ans.size() && curr < ans) ans = curr;
            }
        }
        return ans;
    }
};