class Solution {
public:
    map<char,string> d2l = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, 
                            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

    void combine(vector<string> &res, string temp, string digits) {
        if (digits == "") res.push_back(temp);
        for(int i = 0; i < d2l[digits[0]].size(); i++) {
            combine(res, temp + d2l[digits[0]][i] , string(digits,1));
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        combine(res, "", digits);
        return res;
    }
};