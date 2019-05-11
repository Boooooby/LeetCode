class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;

    	int size = s.size();
    	int batch = numRows + numRows - 2;
    	string result = "";

    	for (int i = 0; i < numRows; i++) {
    		for (int j = 0; j + i < size; j += batch) {
    			result += s[j + i];
    			if (i != 0 && i != numRows - 1 && j + batch - i < size) {
    				result += s[j + batch - i];
    			}
    		}
    	}

    	return result;
    }
};