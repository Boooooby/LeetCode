class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size() - 1, maxVolume = 0, temp = 0;

        while (first < last) {
            if (height[first] < height[last]) {
                temp = height[first];
                maxVolume = max(maxVolume, temp * (last - first));
                while (first < last && height[first] <= temp)
                    first++; 
            }
            else {
                temp = height[last];
                maxVolume = max(maxVolume, temp * (last - first));
                while (first < last && height[last] <= temp)
                    last--;
            }
        }

        return maxVolume;
    }
};