class Solution {
public:

    class SegmentTree{
        public:
            vector<int>seg;
            int n;

            SegmentTree(int n){
                this->n = n;
                seg.resize(4*n + 5);
            }

            int getGcd(int a , int b){
                if(!a) return b;
                if(!b) return a;
                return gcd(a , b);
            }

            void build(vector<int>& arr , int idx , int low , int high){
                if(low == high){
                    seg[idx] = arr[low];
                    return;
                }

                int mid = (low + high) / 2;
                build(arr , 2 * idx , low , mid);
                build(arr , 2 * idx + 1 , mid + 1 , high);
                seg[idx] = getGcd(seg[2 * idx] , seg[2 * idx + 1]);
            }

            void update(int idx , int low , int high , int pos , int val){
                if(low == high){
                    seg[idx] = val;
                    return;
                }

                int mid = (low + high) / 2;

                if(pos <= mid) update(2 * idx , low , mid , pos , val);
                else update(2 * idx + 1 , mid+1 , high , pos , val);

                seg[idx] = getGcd(seg[2 * idx] , seg[2 * idx + 1]);
            }

            int query(int idx , int low , int high , int l , int r){
                if(r < low || high < l) return 0;
                if(l <= low && high <= r) return seg[idx];

                int mid = (low + high) / 2;

                int left = query(2 * idx , low , mid , l , r);
                int right = query(2 * idx + 1 , mid + 1 , high , l , r);

                return getGcd(left , right);
            }
    };

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        int n = nums.size();
        int ans = 0;

        vector<int>b(n);

        for(int i = 0 ; i < nums.size() ; i++){
            b[i] = (nums[i] % p == 0) ? nums[i] / p : 0;
        }

        SegmentTree st(n);

        st.build(b , 1 , 0 , n - 1);
        
        vector<int>prefix(n) , suffix(n);

        for(auto& it : queries){
            int idx = it[0];
            int val = it[1];

            nums[idx] = val;
            b[idx] = (val % p == 0) ? val / p : 0;

            st.update(1 , 0 , n - 1 , idx , b[idx]);

            int CompGCD = st.query(1 , 0 , n-1 , 0 , n-1);

            if(CompGCD != 1) continue;

            bool good = false;

            for(int i = 0; i < n; i++){
                int left = (i == 0) ? 0 : st.query(1,0,n-1,0,i-1);
                int right = (i == n-1) ? 0 : st.query(1,0,n-1,i+1,n-1);

                if(gcd(left, right) == 1){
                    good = true;
                    break;
                }
            }

            if(good) ans++;
        }
        return ans;
    }
};