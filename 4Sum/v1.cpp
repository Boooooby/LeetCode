class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        int s = nums.size();
        
        if (s < 4) return res;
        
        sort(nums.begin(), nums.end());
        for (int first = 0; first < s - 3; first++) {
            if (first > 0 && nums[first - 1] == nums[first]) continue;
            if (nums[first] + nums[s - 1] + nums[s - 2] + nums[s - 3] < target) continue;
            if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) break;

            for (int second = first + 1; second < s - 2; second++) {
                if (second > first + 1 && nums[second - 1] == nums[second]) continue;
                if (nums[first] + nums[second] + nums[s - 1] + nums[s - 2] < target) continue;
                if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break;

                int third = second + 1, fourth = s - 1;
                while (third < fourth) {
                    int sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        res.push_back(vector<int> {nums[first], nums[second], nums[third], nums[fourth]});
                        do {
                            third++;
                        } while (third < fourth && nums[third - 1] == nums[third]);
                        do {
                            fourth--;
                        } while (third < fourth && nums[fourth + 1] == nums[fourth]);
                    }
                    else if (sum < target) 
                        third++;
                    else 
                        fourth--;
                }
            }
        }
        
        return res;
    }
};