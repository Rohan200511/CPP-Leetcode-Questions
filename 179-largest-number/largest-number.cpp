class Solution {
public:
    static bool comp(string& a , string& b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(int num : nums){
            temp.push_back(to_string(num));
        }
        sort(temp.begin() , temp.end() , comp);
        if(temp[0] == "0") return "0";
        string ans = "";
        for(int i = 0 ; i < temp.size() ; i++){
            ans += temp[i];
        }
        return ans;
    }
};