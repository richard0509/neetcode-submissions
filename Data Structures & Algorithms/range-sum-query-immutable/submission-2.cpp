class NumArray {
    std::vector<int> arr;
    std::vector<int> prefix_arr;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        int total = 0;
        for (int n : arr) {
            total += n;
            prefix_arr.emplace_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        int preRight = prefix_arr[right];
        int preLeft = left > 0 ? prefix_arr[left - 1] : 0;
        return preRight - preLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */