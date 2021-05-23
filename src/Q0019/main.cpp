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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unique_ptr<ListNode> dummy{new ListNode{0}};
        dummy->next = head;
        auto first=dummy.get(), second=dummy.get();

        for(int i=0;i<n+1;i++) first=first->next;

        while(first!=NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
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
    PrintList(head);
    auto res = s.removeNthFromEnd(head, 2);
    PrintList(res);
    return 0;
}