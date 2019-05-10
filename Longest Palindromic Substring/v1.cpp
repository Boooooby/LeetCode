// Brute Force

class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if(s[start++] != s[end--]) 
            	return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string longest;
        int size = s.size();
        
        for (int i = 0; size - i > longest.size(); i++) {
            for (int j = size - 1; j - i + 1 > longest.size(); j--) {
                if (isPalindrome(s, i, j)) {
                    longest = s.substr(i, j - i + 1);
                    break;
                }
            }
        }
        return longest;
    }
};