/**
 * Determine whether an integer is a palindrome. An integer is 
 * a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 *   Input: 121
 *   Output: true
 * 
 * Example 2:
 *   Input: -121
 *   Output: false
 * Explanation: From left to right, it reads -121. From right to 
 * left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 *   Input: 10
 *   Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * 
 * Follow up:
 * Coud you solve it without converting the integer to a string?
*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)    return false;            //负数一定不是回文
        
        int len  = 1;                          //记录数的位数
        int t = 1;                             //计算数究竟有多大
        do {
            t = 10 * t;
            if (x < t)    break;
            len++;
        } while (t <= 100000000);

        if (len != 10)    t = t / 10;

        int tmp1 = x, tmp2 = x;
        while (len>0) {
            if (tmp1/t != tmp2%10)
                return false;
            else {
                tmp1 = tmp1 % t;
                tmp2 = tmp2 / 10;
                len = len - 2;
                t = t / 10;
            }
        }
        return true;
        //附上一个48ms完成的别人的代码，我的120ms，好吧别人的思路真的好，跪
        /*int numSrc = x;
        long long numDst = 0;
        if (x < 0)
        {
            return false;
        }

        while (numSrc)
        {
            numDst = numDst * 10 + numSrc % 10;
            numSrc /= 10;
        }

        return (numDst == x);*/
    }
};

int main() {
    int x = 2147447412;
    cout << x << endl;
    cout << Solution().isPalindrome(x) << endl;
    return 0;
}