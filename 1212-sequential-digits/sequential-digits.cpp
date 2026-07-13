class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;

        string s = "123456789";
        int st = to_string(low).length();
        int e = to_string(high).length();

        for(int len = st ; len <= e ; len++){
            int i = 0;

            while(i + len <= s.length()){
                int num = stoi(s.substr(i , len));
                if(num >= low && num <= high) ans.push_back(num);
                i++;
            }
        }
        return ans;
    }
};