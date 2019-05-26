/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*ListNode* l = NULL;         //链表两两合并
        for (auto i = lists.begin(); i != lists.end(); i++)
            l = merge(l, *i);
        return l;*/
        if (lists.size() == 0) {        //分治算法
            return (ListNode*)NULL;
        }
        while (lists.size() > 1) {
            for (int i = 0; i+1 < lists.size(); i++) {
                lists[i] = merge(lists[i], lists[i+1]);
                lists.erase(lists.begin()+i+1);
            }
        }
        return lists[0];
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* cur = &head;
        while (l1 != NULL && l2 != NULL) {
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
    ListNode n1(1),n2(4),n3(5),n4(-1),n5(5),n6(11),n7(6),n8(10);
    n1.next = &n2;  n2.next = &n3;
    n4.next = &n5;  n5.next = &n6;
    n7.next = &n8;
    vector<ListNode*> lists;

    lists.push_back(&n1);
    lists.push_back(&n4);
    lists.push_back(&n7);
    Solution s;
    for (auto i = lists.begin(); i != lists.end(); i++) 
        s.printList(*i);
    cout << "start processing..." << endl;
    ListNode* l = s.mergeKLists(lists);
    s.printList(l);
    return 0;
}