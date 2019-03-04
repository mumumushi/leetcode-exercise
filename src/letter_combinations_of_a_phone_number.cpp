/**
 * Given a string containing digits from 2-9 inclusive, return all 
 * possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) 
 * is given below. Note that 1 does not map to any letters.
 * 
 * 1 => NULL
 * 2 => a,b,c
 * 3 => d,e,f
 * 4 => g,h,i
 * 5 => j,k,l
 * 6 => m,n,o
 * 7 => p,q,r,s
 * 8 => t,u,v
 * 9 => w,x,y,z
 * 0 => NULL
 * 
 * Example:
 *   Input: "23"
 *   Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * Note:
 * Although the above answer is in lexicographical order, your answer 
 * could be in any order you want.
 * 
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:

    vector<string> ans    = {};
    vector<string> codes = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void combine(string digits, int index, string s) {
        if (index == digits.size()) {
            ans.push_back(s);
            return ;
        }

        string code = codes[digits[index] - '0'];

        for(int i = 0; i < code.size(); i++)
            combine(digits, index+1, s+code[i]);
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ans;
        combine(digits, 0, "");
        return ans;
    }
};

int main() {
    string digits = "23";
    cout << digits << endl;
    vector<string> ans = Solution().letterCombinations(digits);

    for (auto i = ans.begin(); i != ans.end(); i++)
        cout << *i << " ";
    cout << endl;
    return 0;
}
