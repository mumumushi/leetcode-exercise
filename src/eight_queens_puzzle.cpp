/**
 * 八皇后问题不是leetcode的题。。。它是letter_combinations_of_a_phone_number.cpp
 * 的扩张学习，主要是为了学习这种回溯法的思路
*/
#include"..\include\head.h"
using namespace std;

/**
 * 数据结构，用一个vector<int> s 表示皇后的位置，分别从第0行到第7行，第0列到第7列
 * 如s = [5, 3, 6, 0, 7, 1, 4, 2]，则表示皇后位于第0行第5列，第1行第3列。。。。
*/

vector<vector<int>> ans;
int n = 8;

/**
 * 因为是按行递归的所以行不用担心，然后就是列
*/
bool isValid(int row, int column, vector<int>& s) {
    for (int i = 0; i < row; i++) {
        /*      判断列              判断对角，行相差数与列相差树相同的话，就是对角 */
        if (s[i] == column || (row-i) == abs(s[i]-column))
            return false; 
    }
    return true;
}

void queen(int row, vector<int>& s) {
    if (row == n) {
        ans.push_back(s);
        return;
    }

    /*对该行所有的列都进行遍历*/
    for (int column = 0; column < n; column++) {   
        if (isValid(row, column, s)) {
            s.push_back(column);
            queen(row+1, s);
            s.pop_back();
        }
    }
}

int main() {
    vector<int> nums = {1,2};
    vector<int> s = {};

    queen(0, s);
    
    /*打印一种解法*/
    s = ans[0];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == s[i])    cout << 1 << " ";
            else              cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
