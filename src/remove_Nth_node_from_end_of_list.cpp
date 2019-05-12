/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*一次遍历，快慢指针实现，快指针先走n步，然后快慢指针一起走
        知道快指针历遍完，注意判断头与尾*/
        ListNode* p = head, *q = NULL;
        int k = 1;
        while (k != n && p != NULL) {
            k++;
            p = p->next;
        } 
        if (p->next == NULL)    return head->next;  //删除头部，尾部的情况
        else                    p = p->next;
        q = head;
        while (p->next != NULL) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
        /*ListNode* ptr = head; //两次历遍，但是leetcode上结果错了，原因暂时不明
        int len;
        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }
        if (n > len)    return NULL;
        ptr = head;
        int j = 1;
        if (len == n)   return head->next;
        len = len - n;
        while (ptr != NULL && j != len) {
            ptr = ptr->next;
            j++;
        }
        if (ptr != NULL && ptr->next != NULL)
            ptr->next = ptr->next->next;

        return head;*/
    }
};

int main(void) {
    ListNode l1(1), l2(2), l3(3), l4(4), l5(5), l6(6);
    // l1.next = &l2;
    // l2.next = &l3;
    // l3.next = &l4;
    // l4.next = &l5;


    ListNode* ptr = &l1;
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << endl;
    Solution s;
    ptr = s.removeNthFromEnd(&l1, 1);
    while (ptr != NULL) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }

    return 0;
}