class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int first = 0; first < nums.size(); first++) {
        	int second = first + 1, third = nums.size() - 1;
        	while (second < third) {
        		int sum = nums[first] + nums[second] + nums[third];
        		
                if (sum == 0) {
        			res.push_back(vector<int> {nums[first], nums[second], nums[third]});
        			do { 
                        second++; 
                    } while (second < third && nums[second - 1] == nums[second]);
        			do { 
                        third--; 
                    } while (second < third && nums[third + 1] == nums[third]);
        		}
        		else if (sum < 0) {
        			second++;
                }
        		else {
        			third--;
                }
        	}         

            while (first + 1 < nums.size() && nums[first + 1] == nums[first]) {
                first++;
            }
        }
        
        return res;
    }
};