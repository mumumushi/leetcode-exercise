/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
if (s.length() == 1)  return false;
        if (s.length() == 0)  return true;
        stack<char> a;
        int i = 0;
        while (i < s.length()) {
            if (s[i]=='{' || s[i]=='[' || s[i]=='(')
                a.push(s[i]);
            else if (s[i]=='}' || s[i]==']' || s[i]==')') {
                if (a.empty())  return false;
                char c = a.top();
                a.pop();
                switch(c) {
                    case '{':if (s[i]!='}') return false;   break;
                    case '[':if (s[i]!=']') return false;   break;
                    case '(':if (s[i]!=')') return false;   break;
                }
            } else return false;
            i++;
        }
        return a.empty();
    }
};

int main() {
    string s = "{{}()";
    cout << s << endl;
    cout << Solution().isValid(s) << endl;
    return 0;
}