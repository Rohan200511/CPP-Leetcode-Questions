class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int i = 0, j = 0, k = 0;
        vector<int> merged(m + n);
        
    
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }

        while (i < m) {
            merged[k++] = nums1[i++];
        }

        while (j < n) {
            merged[k++] = nums2[j++];
        }

        for (int i = 0; i < m + n; ++i) {
            nums1[i] = merged[i];
        }
    }
};