/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern 
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行Z字形排列。
 * on a given number（i.e.numRows=3）of rows like this: 
 * 
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * Example 1:
 *  Input: s = "PAYPALISHIRING", numRows = 3
 *  Output: "PAHNAPLSIIGYIR"
 * 
 * Example 2:
 *  Input: s = "PAYPALISHIRING", numRows = 4
 *  Output: "PINALSIGYAHRPI"
 * Explanation:
 *  P     I    N
 *  A   L S  I G
 *  Y A   H R
 *  P     I
 * 
 * 解题思路：大概就是观察得到每一行相隔的两个字符之间index的规律，这种规律有上下两种
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if (numRows == 1)   return s;         //差点被坑，这里numRows==1直接return，避免后面死循环
        for (int row=1; row <= numRows; row++) {
            int index = row - 1;
            int len = s.length();
            do {
                if (row != numRows) {         //最后一行不执行下规律
                    ans = ans + s[index];
                    index = index + 2*(numRows-row);//是index下规律
                }
                
                if (row != 1) {               //第一行不执行上规律
                    if (index >= len)   break;
                    ans = ans + s[index];
                    index = index + 2*(row-1);//这就是index上规律
                }
            } while (index < len);
        }
        return ans;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    cout << s<< endl;
    cout << Solution().convert(s, 4) << endl;
    return 0;
}