#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <memory>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n=NULL) : val(x), next(n) {}
};

class mycomp{
public:
    bool operator() (const ListNode* lhs, const ListNode* rhs) const {
        return lhs->val > rhs->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unique_ptr<ListNode> dummy{new ListNode{0}};
        auto prev = dummy.get();
        priority_queue<ListNode*, vector<ListNode*>, mycomp> pq;
        for(auto l: lists) {
            if (l == NULL) continue;
            pq.push(l);
        }

        while(pq.size() > 1) {
            auto cur = pq.top();
            prev->next = cur;
            prev = prev->next;
            pq.pop();
            if (cur->next != NULL) pq.push(cur->next);
        }

        if (!pq.empty()) {
            prev->next = pq.top();
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
            4, new ListNode{
                5, NULL
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
    ListNode* l3 = new ListNode{
        2, new ListNode{
            6, NULL
            }
    };

    vector<ListNode*> lists{l1, l2, l3};

    Solution s;
    auto res = s.mergeKLists(lists);
    PrintList(res);
    return 0;
}