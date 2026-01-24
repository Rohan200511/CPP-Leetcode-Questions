class NumArray {
public:
    int n;
    vector<int> bit, nums;

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) add(i, nums[i]);
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }
    
    int sumRange(int left, int right) {
        return prefix(right) - prefix(left - 1);
    }

private:
    void add(int i, int delta) {
        i++;
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }
    
    int prefix(int i) {
        int s = 0;
        i++;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */