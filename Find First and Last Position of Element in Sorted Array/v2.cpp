class Solution {
public:
    int extremeInsertionIndex(vector<int>& nums, int target, bool left) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > target || (left && target == nums[mid]))
                high = mid;
            else 
                low = mid + 1;
        }
        return low;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        
        int left = extremeInsertionIndex(nums, target, true);
        if (left == nums.size() || nums[left] != target) {
            return res;
        }            
        else {
            res[0] = left;
            res[1] = extremeInsertionIndex(nums, target, false) - 1;
        }
        
        return res;
    }
};