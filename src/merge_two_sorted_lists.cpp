/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        while (l1 != NULL && l2 !=NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 == NULL)         cur->next = l2;
        else if (l2 == NULL)    cur->next = l1;
        
        return head.next;
    }

    void printList(ListNode* l) {
        while(l != NULL) {
            cout << l->val << "->";
            l = l->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode l1(1),l2(2),l3(4),l4(1),l5(3),l6(4);
    l1.next = &l2;  //l2.next = &l3;
    l4.next = &l5;  l5.next = &l6;

    Solution s;
    s.printList(&l1);
    s.printList(&l4);
    s.printList(s.mergeTwoLists(&l1,&l4));
    return 0;
}