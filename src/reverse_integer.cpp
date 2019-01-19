/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 * Example 1:
 *  Input: 123
 *  Output: 321
 * Example 2:
 *  Input: -123
 *  Output: -321
 * Example 3:
 *  Input: 120
 *  Output: 21
 * Note:Assume we are dealing with an environment which could only 
 * store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
 * For the purpose of this problem, assume that your function returns 0 
 * when the reversed integer overflows.
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == INT32_MIN)    return 0;                     //因为要按正数处理，先剔除一个溢出的情况
        int ans = 0;
        bool isNegative = false;
        bool mayBeOverflow = false;
        if (x < 0)  {                                        //负数按正数处理
            isNegative = true;
            x = -1 * x;
        }
        if (x/1000000000 != 0)    mayBeOverflow = true;      //假如是十位数，存在overflow的可能

        while (x != 0) {
            if (mayBeOverflow)                               //检测是否将要overflow
                if ((ans>INT32_MAX/10) || (ans==INT32_MAX/10 && x%10>7))    return 0;

            ans = 10*ans + x%10;
            x = x / 10;
        }

        if (isNegative)    ans = -1 * ans;
        return ans;
    }
};

int main() {
    int x = 120;
    cout << x << endl;
    cout << Solution().reverse(x) << endl;
    return 0;
}