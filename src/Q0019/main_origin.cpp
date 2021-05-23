#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        auto p = head;
        while(p!=NULL) {
            nodes.push_back(p);
            p = p->next;
        }
        auto m = nodes.size() - n;  // mth from begin
        if (m == 0) return head->next;

        nodes[m-1]->next = nodes[m]->next;
        return head;
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