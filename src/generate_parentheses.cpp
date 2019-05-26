/*
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {     //回溯递归
        vector<string> ans;
        if (n <= 0) {
            ans.push_back("");
            return ans;
        }
        generate(ans, "", 0, 0, n);
        return ans;
    }

    void generate(vector<string>& v, string s, int left, int right, int n) {
        if (left > n || right > n)    return ;
        if (left == n && right == n) {
            v.push_back(s);
            return ;
        }   

        if (left >= right) {
            //string s1 = string(s);
            generate(v, s+"(", left+1, right, n);
            //可以选择把s的最后一位
            generate(v, s+")", left, right+1, n);
        }
    }
};

int main() {
    int n = 3;
    Solution s;
    vector<string> ans = s.generateParenthesis(n);
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}