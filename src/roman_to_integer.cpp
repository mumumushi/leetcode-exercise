/**
 * Roman numerals are represented by seven different symbols
 * : I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just 
 * two one's added together. Twelve is written as, XII, which 
 * is simply X + II. The number twenty seven is written as XXVII, 
 * which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left 
 * to right. However, the numeral for four is not IIII. Instead, 
 * the number four is written as IV. Because the one is before 
 * the five we subtract it making four. The same principle applies 
 * to the number nine, which is written as IX. There are six instances 
 * where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is 
 * guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 *   Input: "III"
 *   Output: 3
 * 
 * Example 2:
 *   Input: "IV"
 *   Output: 4
 * 
 * Example 3:
 *   Input: "IX"
 *   Output: 9
 * 
 * Example 4:
 *   Input: "LVIII"
 *   Output: 58
 *   Explanation: L = 50, V= 5, III = 3.
 * 
 * Example 5:
 *   Input: "MCMXCIV"
 *   Output: 1994
 *   Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int len = s.size();
        int index = 0;
        while (index < len) {
            switch(s[index]) {
                case 'M':{
                    ans = ans + 1000;
                    index++;
                }break;
                case 'D':{
                    ans = ans + 500;
                    index++;
                }break;
                case 'C':{
                    if (index+1<len) {
                        char c = s[index+1];
                        if      (c == 'M')  {  ans+=800;  index++;  }
                        else if (c == 'D')  {  ans+=300;  index++;  }
                    }
                    ans = ans + 100;
                    index++;
                }break;
                case 'L':{
                    ans = ans + 50;
                    index++;
                }break;
                case 'X':{
                    if (index+1 < len) {
                        char x = s[index+1];
                        if      (x == 'C')  {  ans+=80;  index++;  }
                        else if (x == 'L')  {  ans+=30;  index++;  }
                    }
                    ans = ans + 10;
                    index++;
                }break;
                case 'V':{
                    ans = ans + 5;
                    index++;
                }break;
                case 'I':{
                    if (index+1 < len) {
                        char i = s[index+1];
                        if      (i == 'X')  {  ans+=8;  index++;  }
                        else if (i == 'V')  {  ans+=3;  index++;  }
                    }
                    ans = ans + 1;
                    index++;
                }break;
                default:    return 0;
            }
        }
        return ans;
    }
};

int main() {
    string s = "IV";
    cout << s << endl << Solution().romanToInt(s) << endl;
    return 0;
}