class Solution {
public:
	void addParenthesis(vector<string> &res, string cur, int lcount, int rcount) {		
		if (lcount == 0 && rcount == 0) {
			res.push_back(cur);
			return;
		}

		if (lcount > 0 && lcount <= rcount) {
			addParenthesis(res, cur + '(', lcount - 1, rcount);
			addParenthesis(res, cur + ')', lcount, rcount - 1);
		}
		else if (rcount > 0) {
			addParenthesis(res, cur + ')', lcount, rcount - 1);
		}
	}

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addParenthesis(res, "", n, n);
        return res;
    }
};