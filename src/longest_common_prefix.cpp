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
        return prefix;
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}