/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:
 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 *  Explanation: 342 + 465 = 807.
*/
#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
		int carry = 0;
		ListNode* head = (ListNode*)calloc(1, sizeof(ListNode));
		ListNode* tail = head;
		
		do {
			int x = (l1 != NULL) ? l1->val : 0;
			int y = (l2 != NULL) ? l2->val : 0;
			sum = x + y + carry;
			if (carry == 1)	carry = 0;
			if (sum >= 10) {
				carry = 1;
				sum = sum - 10;
			}
			ListNode* n = (ListNode*)calloc(1, sizeof(ListNode));
			n->val = sum;

			tail->next = n;
			tail = n;
			l1 = (l1 != NULL) ? l1->next : NULL;
			l2 = (l2 != NULL) ? l2->next : NULL;
		} while (l1 != NULL || l2 != NULL);
		
		if (carry == 1) {
			ListNode* n = (ListNode*)calloc(1, sizeof(ListNode));
			n->val = carry;

			tail->next = n;
		}
		return head->next;
    }
};

int main(void)
{
    ListNode l1(2), l2(4), l3(3);
    ListNode n1(5), n2(6), n3(9);
    l1.next = &l2; l2.next = &l3;
    n1.next = &n2; n2.next = &n3;

    Solution s;
    ListNode* ans = s.addTwoNumbers(&l1, &n1);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
