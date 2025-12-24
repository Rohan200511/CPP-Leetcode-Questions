class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        sort(capacity.begin() , capacity.end() , greater<>());
        int ans = 0;

        int sum = accumulate(apple.begin() , apple.end() , 0);

        for(auto& c : capacity){
            sum -= c;
            ans += 1;
            if(sum <= 0) break;
        }
        return ans;
    }
};