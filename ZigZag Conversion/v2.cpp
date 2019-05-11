class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;

    	vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0, isDown = -1;
        string result = "";

        for (char c : s) {
            rows[curRow] += c;

            if (curRow == 0 || curRow == numRows - 1) {
                isDown = -isDown;
            }

            curRow += isDown;
        }

        for (string row : rows) {
            result += row;
        }

    	return result;
    }
};