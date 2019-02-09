/**
 * Write a function to find the longest common prefix string 
 * amongst an array of strings.If there is no common prefix, 
 * return an empty string "".
 * 
 * Example 1:
 *   Input: ["flower","flow","flight"]
 *   Output: "fl"
 * 
 * Example 2:
 *   Input: ["dog","racecar","car"]
 *   Output: ""
 *   Explanation: There is no common prefix among the input strings.
 * 
 * Note:
 *   All given inputs are in lowercase letters a-z.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int i = 0;
        int j = 0;
        char c = '\0';
        int n = strs.size();

        if (n == 0) return prefix;

        while (true) {
            if (j < strs[0].size())       //先提取第一项的第j个字符
                c = strs[0][j];
            else return prefix;

            for (i = 1; i < n; i++) {     //对每一项的第j个字符进行判断
                if (j >= strs[i].size())
                    return prefix;
                if (c != strs[i][j])
                    return prefix;
            }
            prefix = prefix + c;
            j++;
        }
        return prefix;
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}