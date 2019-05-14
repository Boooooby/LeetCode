class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size() - 1, maxVolume = 0, temp = 0;

        while (first != last) {
        	temp = (last - first) * min(height[first], height[last]);
        	maxVolume = (temp > maxVolume) ? temp : maxVolume;

        	if (height[first] < height[last])
        		first++;
        	else
        		last--;
        }

        return maxVolume;
    }
};