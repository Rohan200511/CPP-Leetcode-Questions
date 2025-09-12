class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i =0 , j=0;
        vector<int>merged;
        
        while(i<a.size() && j<b.size()){
            if(a[i] <= b[j]) merged.push_back(a[i++]);
            else merged.push_back(b[j++]);
        }
        while(i<a.size()) merged.push_back(a[i++]);
        while(j<b.size()) merged.push_back(b[j++]);
        
        return merged[k-1];
    }
};