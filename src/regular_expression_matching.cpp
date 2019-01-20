/**
 * Given an input string (s) and a pattern (p), implement 
 * regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 * 
 * Example 1:
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * Example 2:
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. 
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * Example 3:
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * Example 4:
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. 
 * Therefore it matches "aab".
 * 
 * Example 5:
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        /*int len1 = s.length(), len2 = p.length();
        int m = 0, n = 0;
        char a = '\0', b = '\0';
        bool isFinishS = false;
        while (m < len1 && n < len2) {
            a = s[m];
            b = p[n];

            if (a != b) {
                if (b == '.') {                   //  .*  一起出现的情况
                    if (p[n+1] == '*') {
                        n += 2;
                        m = len1;
                    } else {
                        m++; n++;
                    }
                        
                } else if (p[n+1] == '*' && n+1 < len2) { //  X*  出现，即重复了零次
                    n += 2;
                    if (isFinishS) m = len1;
                }        
                else                             //不同，false
                    return false;

            } else {                             //普通相同
                if (p[n+1] == '*' && n+1 < len2) {             //相同且 x*重复多次
                    n += 2;
                    m++;
                    while (s[m] == a && m < len1)
                        m++;
                    while (p[n] == a && n < len2)   
                        n++;
                } else {
                    m++; n++;
                }
            }
            if (m == len1 && n < len2) {
                isFinishS = true;
                int tmp = n;
                m = m - 1;
                while (p[tmp] >= 'a' && p[tmp] <= 'z' && tmp < len2)
                    tmp++;
                if (tmp == len2)
                    return false;
            }
        }
        return (m == len1) && (n == len2);*/
        int len1 = s.length(), len2 = p.length();
        int m = 0, n = 0;
        char a = '\0', b = '\0';
        bool isFinishS = false;
        while (m < len1 && n < len2) {
            a = s[m];
            b = p[n];

            if (a != b) {
                if (b == '.') {                   //  .*  一起出现的情况
                    if (p[n+1] == '*') {
                        n += 2;
                        m = len1;
                    } else {
                        m++; n++;
                    }
                        
                } else if (p[n+1] == '*' && n+1 < len2) { //  X*  出现，即重复了零次
                    n += 2;
                    if (isFinishS) m = len1;
                }        
                else                             //不同，false
                    return false;

            } else {                             //普通相同
                if (p[n+1] == '*' && n+1 < len2) {             //相同且 x*重复多次
                    n += 2;
                    m++;
                    while (s[m] == a && m < len1)
                        m++;
                    while (p[n] == a && n < len2)   
                        n++;
                } else {
                    m++; n++;
                }
            }
            if (m == len1 && n < len2) {
                isFinishS = true;
                int tmp = n;
                m = m - 1;
                while (p[tmp] >= 'a' && p[tmp] <= 'z' && tmp < len2)
                    tmp++;
                if (tmp == len2 && p[tmp-1] != a)
                    return false;
            }
        }
        if (isFinishS)    m = len1;
        return (m == len1) && (n == len2);
    }
};

int main() {
    string s = "aaa";
    string p = "aaaa";
    cout << "s = " << s << endl << "p = " << p << endl;
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}