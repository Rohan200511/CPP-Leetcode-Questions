class Solution {
public:

    string result = "";
    int count = 0;

    void dfs(int n , int k , string& curr){
        if(curr.size() == n){
            count++;
            if(count == k){
                result = curr;
            }
            return;
        }

        for(auto c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                curr.push_back(c);
                dfs(n , k , curr);
                curr.pop_back();

                if(!result.empty()) return;
            }
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        dfs(n , k , curr);
        return result;
    }
};