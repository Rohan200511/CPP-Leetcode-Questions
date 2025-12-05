class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n) , right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++) left[i] = left[i-1] + nums[i];

        for(int j = n - 2 ; j >= 0 ; j--) right[j] = right[j + 1] + nums[j];

        int count = 0;

        int x = 0 , y = 1;

        while(x < n && y < n){
            if((left[x] - (right[y])) % 2 == 0) count++;
            x++;
            y++;
        }
        return count;
    }
};