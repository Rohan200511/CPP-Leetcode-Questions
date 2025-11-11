class Solution {
public:

    int squared(vector<int>& p){
        int square = p[0] * p[0] + p[1] * p[1];
        return square;
    }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>> maxheap;

        for(auto& p : points){
            int dist = squared(p);
            if(maxheap.size() < k) maxheap.push({dist , p});

            else if(dist < maxheap.top().first){
                maxheap.pop();
                maxheap.push({dist , p});
            }
        }
        vector<vector<int>>ans;
        while(!maxheap.empty()) {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
};