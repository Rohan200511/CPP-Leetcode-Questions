class Solution {
public:
    typedef pair<int , int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(auto& it : nums) mp[it]++;
        

        priority_queue<P , vector<P> , greater<P>>pq;

        for(auto& it : mp){
            int num = it.first;
            int count = it.second;

            pq.push({count , num});
            if(pq.size() > k) pq.pop();
        }

        vector<int>ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};