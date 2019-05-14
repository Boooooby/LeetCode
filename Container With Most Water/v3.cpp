class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size() - 1, maxVolume = 0;

        while (first < last) {
            int minHeight = min(height[first], height[last]);
            maxVolume = max(maxVolume, minHeight * (last - first));
            while (height[first] <= minHeight && first < last) first++;
            while (height[last] <= minHeight && first < last) last--;
        }

        return maxVolume;
    }
};