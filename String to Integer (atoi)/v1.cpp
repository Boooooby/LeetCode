#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	if (str.size() == 0) return 0;

        string num = "";
        bool sign = true, numberBegin = false, isOver = false;

        for (char c : str) {
        	if (c == ' ' && !numberBegin) {
        		continue;
        	}
        	else if (c == '-' && !numberBegin) {
        		sign = false;
        		numberBegin = true;
        	}
        	else if (c == '+' && !numberBegin) {
        		sign = true;
        		numberBegin = true;
        	}
        	else if (c >= '0' && c <= '9') {
        		num += c;
        		numberBegin = true;
        	}
        	else {
        		break;
        	}
        }

        if (num.size() == 0) return 0;

        long sum = num[0] - '0';
        for (int i = 1; i < num.size(); i++) {
        	sum *= 10;
        	sum += num[i] - '0';
        	cout << sum << endl;
        	if (sum > 2147483647) {
        		sum = sign ? 2147483647 : 2147483648;
        		break;
        	}
        }

        return sign ? sum : -sum;
    }
};

int main() {
	Solution *solution = new Solution();
	string str = "-91283472332";
	cout << solution->myAtoi(str) << endl;
	return 0;
}