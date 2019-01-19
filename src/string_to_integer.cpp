/**
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary
 * until the first non-whitespace character is found. Then, starting from
 * this character, takes an optional initial plus or minus sign followed 
 * by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral 
 * number,which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral 
 * number,or if no such sequence exists because either str is empty or it contains 
 * only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned.
 * 
 * Note:
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store 
 * integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
 * If the numerical value is out of the range of representable values, 
 * INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
 * 
 * Example 1:
 *  Input: "42"
 *  Output: 42
 * 
 * Example 2:
 *  Input: "   -42"
 *  Output: -42
 * Explanation: The first non-whitespace character is '-', which is the 
 * minus sign.Then take as many numerical digits as possible, which gets 42.
 * 
 * Example 3:
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not 
 * a numerical digit.
 * 
 * Example 4:
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not 
 * a numerical digit or a +/- sign. Therefore no valid conversion could 
 * be performed.
 * 
 * Example 5:
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.Thefore INT_MIN (−2^31) is returned.
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int index = 0;
        int len = str.length();
        bool isNegative = false;
        char a = str[index];
        while (a == ' ') {
            if (++index==len)    return 0;                      //全是空格
            a = str[index];
        }
        if ((a<'0'||a>'9')&&(a!='+'&&a!='-'))   return 0;       //首非空字符排除

        char temp = str[index+1];                               //处理符号位+-
        if      (a=='+' && temp>='0' && temp<='9')    { a = temp; index++; }
        else if (a=='-' && temp>='0' && temp<='9')    { isNegative = true; a = temp; index++; }
        
        while (index < len) {                                  
            a = str[index];
            if (a < '0' || a > '9')      break;                //非数字结束
            //溢出处理
            if      (isNegative==false&& (ans>(INT32_MAX/10)    
                     || (ans==(INT32_MAX/10) && a>'7')))    return INT32_MAX;
            else if (isNegative==true && (ans>(INT32_MAX/10)
                     || (ans==(INT32_MAX/10) && a>'8')))    return INT32_MIN;
            
            ans = 10*ans + (a-'0');                             //计算数值
            index++;
        }

        if (isNegative)    ans = -1 * ans;
        return ans;
    }
};

int main() {
    string str = "-3147483641";
    cout << str << endl;
    cout << Solution().myAtoi(str) << endl;
    return 0;
}