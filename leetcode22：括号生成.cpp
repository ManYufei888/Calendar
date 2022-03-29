#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        res.push_back("()");
        for (int i = 2; i <= n; i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                string temp1, temp2;
                res.push_back("(" + res[j] + ")");
                temp1 = "()" + res[j];
                temp2 = res[j] + "()";
                if (temp1 == temp2) {
                    res.push_back(temp1);
                }
                else {
                    res.push_back(temp1);
                    res.push_back(temp2);
                }
            }
            res.erase(res.begin(), res.begin() + n);
        }
        return res;
    }
};

class Solution1 {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return res;
        }
        getParenthesis("", n, n);
        return res;
    }

private:
    void getParenthesis(string str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        if (left == right) {
            //剩余左右括号数相等，下一个只能用左括号
            getParenthesis(str + "(", left - 1, right);
        }
        else if (left < right) {
            //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
            if (left > 0) {
                getParenthesis(str + "(", left - 1, right);
            }
            getParenthesis(str + ")", left, right - 1);
        }
    }
};

int main() {
    int n = 4;
    Solution1 solution;
    vector<string> result = solution.generateParenthesis(n);
    for (auto s : result) {
        cout << s << endl;
    }
}