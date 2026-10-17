class Solution {
public:

    long long int digiSum(int num){
        long long int sum = 0;

        while(num != 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<long long int , int>>arr;

        for(int i = 0 ; i < n ; i++){
            long long int sumD = digiSum(nums[i]);
            arr.push_back({sumD , i});
        }

        sort(arr.begin() , arr.end() , [&](auto& a , auto& b){
            if(a.first == b.first){
                return nums[a.second] < nums[b.second];
            }
            return a.first < b.first;
        });

        int swaps = 0;

        unordered_set<int>visited;

        for(int i = 0 ; i < n ; i++){
            if (visited.count(i) || arr[i].second == i) {
                continue;
            }
            
            int cycle_size = 0;
            int curr = i;
            
            while (!visited.count(curr)) {
                visited.insert(curr);
                curr = arr[curr].second;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;

    }
};