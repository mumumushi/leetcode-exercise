/**
 * Roman numerals are represented by seven different symbols: 
 * I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just 
 * two one's added together. Twelve is written as, XII, which 
 * is simply X + II. The number twenty seven is written as XXVII, 
 * which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from 
 * left to right. However, the numeral for four is not IIII. 
 * Instead, the number four is written as IV. Because the one 
 * is before the five we subtract it making four. The same 
 * principle applies to the number nine, which is written as IX. 
 * There are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral. Input is 
 * guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 *   Input: 3
 *   Output: "III"
 * 
 * Example 2:
 *   Input: 4
 *   Output: "IV"
 * 
 * Example 3:
 *   Input: 9
 *   Output: "IX"
 * 
 * Example 4:
 *   Input: 58
 *   Output: "LVIII"
 *   Explanation: L = 50, V = 5, III = 3.
 * 
 * Example 5:
 *   Input: 1994
 *   Output: "MCMXCIV"
 *   Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        while (num >= 1) {
            if (num >= 1000) {
                num = num - 1000;
                ans = ans + "M";
            } else if (num >= 900) {
                num = num - 900;
                ans = ans + "CM";
            } else if (num >= 500) {
                num = num - 500;
                ans = ans + "D";
            } else if (num >= 400) {
                num =  num - 400;
                ans = ans + "CD";
            } else if (num >= 100) {
                num = num - 100;
                ans = ans + "C";
            } else if (num >= 90) {
                num = num - 90;
                ans = ans + "XC";
            } else if (num >= 50) {
                num = num - 50;
                ans = ans + "L";
            } else if (num >= 40) {
                num = num - 40;
                ans = ans + "XL";
            } else if (num >= 10) {
                num = num - 10;
                ans = ans + "X";
            } else if (num >= 9) {
                num = num - 9;
                ans = ans + "IX";
            } else if (num >= 5) {
                num = num - 5;
                ans = ans + "V";
            } else if (num >= 4) {
                num = num - 4;
                ans = ans + "IV";
            } else if (num >= 1) {
                num = num - 1;
                ans = ans + "I";
            }
        }
        return ans;
    }
};

int main() {
    int num = 3999;
    cout << num << endl << Solution().intToRoman(num) << endl;
    return 0;
}