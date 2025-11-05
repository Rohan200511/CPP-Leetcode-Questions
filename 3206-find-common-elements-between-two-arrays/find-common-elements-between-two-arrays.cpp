class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0 , count2 = 0;
        set<int>st1(nums2.begin(),nums2.end());

        for(int i = 0 ; i < nums1.size() ; i++){
            if(st1.count(nums1[i])) count1++;
        }
        
        set<int>st2(nums1.begin(),nums1.end());

        for(int j = 0 ; j < nums2.size() ; j++){
            if(st2.count(nums2[j])) count2++;
        }

        return {count1 , count2};
    }
};