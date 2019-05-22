class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, block[9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int temp = 1 << (board[i][j] - '0');
                    if (row[i] & temp || col[j] & temp || block[i / 3 * 3 + j / 3] & temp) {
                        return false;
                    }
                    row[i] |= temp;
                    col[j] |= temp;
                    block[i / 3 * 3 + j / 3] |= temp;
                }
            }
        }
        return true;
    }
};