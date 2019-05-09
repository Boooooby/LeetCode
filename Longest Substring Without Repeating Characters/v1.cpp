class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int max = 0, size = 0, begin = 0, end = 0, temp = 0, tags[128];
    	for (int i = 0; i < 128; i++) {
    		tags[i] = -1;
    	}

        for (int i = 0; i < s.length(); i++) {
        	if (tags[s[i]] != -1) {
        		size = end - begin + 1;
        		max = (size > max) ? size : max;
        		temp = begin;
        		begin = tags[s[i]] + 1;
        		for (int j = temp; j <= tags[s[i]]; j++) {
        			tags[s[j]] = -1;
        		}       		  		
        		tags[s[i]] = i;
        	}
        	else {
        		tags[s[i]] = i;
        		end = i;
        		size = end - begin + 1;
        		max = (size > max) ? size : max;
        	}        	
        }

        return max;
    }
};