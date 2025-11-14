class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        priority_queue<
                        pair<int , pair<int , int>> , 
                        vector<pair<int , pair<int , int>>> , 
                        greater<pair<int , pair<int , int>>>
                       >pq;
        set<pair<int,int>> seen;

        pq.push({nums1[0] + nums2[0] , {0 , 0}});
        seen.insert({0,0});

        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i] , nums2[j]});

            if( j+1 < m && seen.find({i , j+1}) == seen.end()){
                pq.push({nums1[i] + nums2[j+1] , {i , j+1}});
                seen.insert({i,j+1});
            }

            if( i+1 < n && seen.find({i+1 , j}) == seen.end()){
                pq.push({nums1[i+1] + nums2[j] , {i+1 , j}});
                seen.insert({i+1,j});
            }
        }
        return ans;
    }
};