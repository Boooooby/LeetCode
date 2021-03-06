class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target && res[0] == -1) {
                res[0] = i;
                res[1] = i;
            }
            else if (nums[i] == target && res[0] != -1) {
                res[1] = i;
            }
        }
        return res;
    }
};