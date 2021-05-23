#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    void reverse(ListNode* start, ListNode* end, ListNode* g_p) {
        ListNode* g_n = end->next;
        ListNode* p = g_p;
        ListNode* c = start;
        ListNode* n = start->next;
        while(1) {
            c->next = p;
            if (c == end) {
                start->next = n;
                break;
            }
            p = c;
            c = n;
            n = n->next;
        }
        start->next = g_n;
        if (g_p != NULL) g_p->next = end;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* g_p = NULL;
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* res_head = NULL;
        int count = 1;
        start = end = head;
        while(end->next != NULL) {
            end = end->next;
            count += 1;
            if (count == k) {
                ListNode* new_start = end->next;
                reverse(start, end, g_p);

                if (res_head==NULL) {res_head = end;}
                end = start;
                g_p = start;
                start = new_start;
                count = 0;
            }
        }
        if (res_head==NULL) res_head = head;
        return res_head;
    }
};


void printList(ListNode* head) {
    if (head == NULL) {
        cout << endl;
        return;
    }
    cout << head->val << " ";
    printList(head->next);
}


int main() {
    ListNode* head = new ListNode{
        1, new ListNode{
            2, new ListNode{
                3, new ListNode{
                    4, new ListNode{
                        5, NULL
                    }
                }
            }
        }
    };
    Solution s;
    printList(head);
    auto res = s.reverseKGroup(head, 2);
    printList(res);
    return 0;
}