class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (target == nums[0]) return 0;
        if (target == nums[n - 1]) return n - 1;
        if (n < 2) return -1;
        
        if (target > nums[0]) {
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[i - 1]) break;
                if (nums[i] == target) return i;
            }
        }
        else {
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] > nums[i + 1]) break;
                if (nums[i] == target) return i;
            }
        }
        return -1;
    }
};