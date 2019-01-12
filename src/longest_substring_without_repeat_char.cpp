/**
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 *  Input: "abcabcbb"
 *  Output: 3 
 *  Explanation: The answer is "abc", with the length of 3. 
 * 
 * Example 2:
 *  Input: "bbbbb"
 *  Output: 1
 *  Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 *  Input: "pwwkew"
 *  Output: 3
 *  Explanation: The answer is "wke", with the length of 3. 
 *  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int N = s.length();
		int len = 0, max_len = 0 ;
		bool bag[96] = { false };	//26个字母与一个空格
		int index = 0;
		int last_flag = 0;

		for (int i = 0; i < N; i++) {
			index = s[i] - ' ';

			if (bag[index] == false) {
				len++;
				bag[index] = true;
			}
			else {
				max_len = (len > max_len) ? len : max_len;
				char cur_char = s[i];
				bool flag = false;
				int last_flag_temp = last_flag;
				for (int j = i - 1; j >= last_flag_temp; j--) {
					if (s[j] == cur_char) {
						len = i - j;
						flag = true;
						last_flag = j + 1;
					}
					if (flag) bag[s[j] - ' '] = false;
				}
				
				bag[index] = true;
			}
		}
		max_len = (len > max_len) ? len : max_len;
		return max_len;
		/*上面那个24ms，注释的这个32ms。。。
        int N = s.length();
		int len = 0, max_len = 0 ;
		bool bag[96] = { false };	//26个字母与一个空格
		int index = 0;

        int i = 0, j = 0;
        while(i < N && j < N) {
            index = s[j] - ' ';

            if (bag[index] == false) {
                j++;
				max_len = ((j-i) > max_len) ? (j-i) : max_len;
				bag[index] = true;
			}
			else {
                bag[s[i++]-' '] = false;
			}
        }
		return max_len;*/
	}
};

int main() {
	Solution f;
	string s = "abcabcbb";
	int ans = 0;
	ans = f.lengthOfLongestSubstring(s);
	cout << "max length of substring is " << ans << endl;
	return 0;
}
