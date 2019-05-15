class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {     
        if (nums.size() < 3) 
            return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size(); first++) {
        	int second = first + 1, third = nums.size() - 1;
        	while (second < third) {
        		int sum = nums[first] + nums[second] + nums[third];
        		if (sum == target) 
                    return target;
        		if ((abs(res - target) > abs(sum - target)))	
                    res = sum;
                if (sum > target) third--;
                else second++;
        	}   
            while (first + 1 < nums.size() && nums[first + 1] == nums[first]) first++;
        }
        return res;
    }
};