#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n=NULL) : val(x), next(n) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        unique_ptr<ListNode> dummy{new ListNode{0}};
        ListNode* prev = dummy.get();
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(1) {
            if (p1 == NULL) {
                p1 = p2;
                p2 = NULL;
            }
            if (p2 == NULL) {
                // for p1
                // while(p1!=NULL) {
                //     prev->next = p1;
                //     prev = prev->next;
                //     p1 = p1->next;
                // }
                prev->next = p1;
                break;
            }
            if(p1->val <= p2->val) {
                prev->next = p1;
                prev = prev->next;
                p1 = p1->next;
            }
            else{
                prev->next = p2;
                prev = prev->next;
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};


void PrintList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    ListNode* l1 = new ListNode{
        1, new ListNode{
            2, new ListNode{
                4, NULL
            }
        }
    };
    ListNode* l2 = new ListNode{
        1, new ListNode{
            3, new ListNode{
                4, NULL
            }
        }
    };

    Solution s;
    PrintList(l1);
    PrintList(l2);
    auto res = s.mergeTwoLists(l1, l2);
    PrintList(res);
    return 0;
}