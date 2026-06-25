class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        int slow2 = 0;
        do {
            slow = nums[slow];
            slow2 = nums[slow2];
        } while (slow != slow2);

        return slow;
    }
};
