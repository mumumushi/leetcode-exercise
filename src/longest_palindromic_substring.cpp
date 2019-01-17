/**
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 * Example 1:
 *  Input: "babad"
 *  Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 *  Input: "cbbd"
 *  Output: "bb"
 * Example 3:
 *  Input: "bb"
 *  Output: "bb"
 * Example 4:
 *  Input: "ccccs"
 *  Output: "cccc"
 * 
 * :D
 * 执行用时: 8 ms, 在Longest Palindromic Substring的C++提交中击败了89.89% 的用户
 * 
 * 解题思路：对字符串的第i位（0<=i<=s.length），向它的左右两边检查，从offset=0开始，
 * 若两边相等，增大offset，若不相等，再检查右边的i+isRepeat+offset=1是否于当前i位的
 * 字符相同，相同则增加isRepeat,再修正offset=0。继续循环
*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = s.length();
        int maxPalinLen = 1;
        int i = 0;
         
        for (i = 0; i < len; i++) {                             //历遍字符串的每一位
            int offset = 0;
            int isRepeat = 0;
            //对每一位的两边进行检查
            for (; (i-offset>=0 && i+isRepeat+offset<len) || (i+isRepeat+offset<len && s[i]==s[i+isRepeat+offset] && offset==1); offset++) {
                if (s[i-offset] != s[i+isRepeat+offset]) {      //记录有重复的，修正offset
                    if (s[i] == s[i+isRepeat+offset] && offset == 1) {
                        isRepeat++;
                        offset = 0;
                    }
                    else break;
                }
            }
            offset--;

            if (2*offset+1+isRepeat >= maxPalinLen) {
                maxPalinLen = 2 * offset + 1 + isRepeat;
                ans = s.substr(i-offset, maxPalinLen);
            }
                
        }
        return ans;
    }
};

int main() {
    string s = "abcssssssssc";
    cout << s << endl;
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}