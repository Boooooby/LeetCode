class Solution {
public:
    int closet(int num1, int num2, int target) {
        return (abs(num1 - target) < abs(num2 - target)) ? num1 : num2;
    }

    int threeSumClosest(vector<int>& nums, int target) {     
        sort(nums.begin(), nums.end());
        int res = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
        for (int first = 0; first < nums.size(); first++) {
        	int second = first + 1, third = nums.size() - 1;
        	while (second < third) {
        		int sum = nums[first] + nums[second] + nums[third];
        		if (sum == target) 
        			return target;
        		else if (sum < target) {
                    do { second++; } while (second < third && nums[second - 1] == nums[second]);
                    res = closet(res, sum, target);
                }       			
        		else {
                    do { third--; } while (second < third && nums[third + 1] == nums[third]);
                    res = closet(res, sum, target);
                }     			
        	}         
            while (first + 1 < nums.size() && nums[first + 1] == nums[first]) first++;
        }
        return res;
    }
};