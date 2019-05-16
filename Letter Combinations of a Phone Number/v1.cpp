#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> combine(vector<string> curStr, string newDigit) {

        if (newDigit.size() == 0) 
            return curStr;

        vector<string> res;
        if (curStr.size() == 0) {
            for (int i = 0; i < newDigit.size(); i++) {
                res.push_back("" + newDigit[i]);
            }
            return res;
        }
        
        for (int i = 0; i < curStr.size(); i++) {
            for (int j = 0; j < newDigit.size(); j++) {
                res.push_back(curStr[i] + newDigit[j]);
            }
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        string d2l[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        for (int i = 0; i < digits.size(); i++) {
            res = combine(res, d2l[digits[i] - '0']);
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> temp = solution->letterCombinations("234");
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << endl;
    }
    return 0;
}