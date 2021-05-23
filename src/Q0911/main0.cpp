#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

class TopVotedCandidate {
public:
    map<int, int> time2person_;

    // template<typename T>
    struct LinkNode {
        LinkNode* next_;
        LinkNode* prev_;
        int person_;
        int vote_;
    };

    struct LinkList {
        LinkNode* head_;
        void insertNode(LinkNode* node) {
            if (head_ == NULL) {
                head_ = node;
                node->prev_ = NULL;
                return;
            }
            auto cur = head_;
            LinkNode* prv = NULL;
            while (cur != NULL) {
                if (cur->vote_ <= node->vote_) {
                    break;
                }
                else {
                    prv = cur;
                    cur = cur->next_;
                }
            }
            if (cur == NULL) {
                node->next_ = NULL;
                node->prev_ = prv;
            }
            else {
                cur->prev_ = node;
                node->prev_ = prv;
                node->next_ = cur;
            }
            if (prv != NULL) {
                prv->next_ = node;
            }
            if (cur == head_) {
                head_ = node;
            }
        }
        void move(LinkNode* new_node, LinkNode* cur_node) {
            auto cur_prev = cur_node->prev_;
            auto cur_next = cur_node->next_;
            if (cur_prev != NULL) {cur_prev->next_ = cur_next;}
            if (cur_next != NULL) {cur_next->prev_ = cur_prev;}
            auto new_prev = new_node->prev_;
            // auto new_next = new_node->next_;
            cur_node->prev_ = new_prev;
            cur_node->next_ = new_node;
            if (new_prev != NULL) {new_prev->next_ = cur_node;}
            else {head_ = cur_node;}
            new_node->prev_ = cur_node;
            // if (new_next != NULL) {new_next->prev_ = cur_node;}
        }
    };

    void PrintLinkList(LinkList& ll) {
        auto node = ll.head_;
        while (node != NULL) {
            cout << "person " << node->person_ << " vote " << node->vote_ << ", ";
            node = node->next_;
        }
        cout << endl;
    }

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        auto vote_num = persons.size();
        // vector<pair<int, int>> person_vote_rank;
        LinkList llist {NULL};
        // LinkNode* tail=NULL;

        map<int, LinkNode*> person2node;

        for(int cur_vote=0; cur_vote<vote_num; cur_vote++) {
            auto cur_per = persons[cur_vote];
            // adjust rank by new vote
            auto it = person2node.find(cur_per);
            if (it == person2node.end()) {
                LinkNode* cur_node = new LinkNode{NULL, NULL, cur_per, 1};
                llist.insertNode(cur_node);
                person2node[cur_per] = cur_node;
            }
            else {
                auto cur_node = it->second;
                cur_node->vote_ += 1;
                auto new_node = cur_node;
                while (new_node->prev_ != NULL) {
                    if (new_node->prev_ == NULL || new_node->prev_->vote_ > cur_node->vote_) {
                        break;
                    }
                    else {
                        new_node = new_node->prev_;
                    }
                }
                // cout << "New Node is: person " << new_node->person_ << " vote " << new_node->vote_ <<
                    // ". Cur Node is: person " << cur_node->person_ << " vote " << cur_node->vote_ << endl;
                // move cur_node before new_node
                if (new_node != cur_node) {
                    llist.move(new_node, cur_node);
                }
            }
            
            // get candidate person at cur_time
            auto max_person = llist.head_->person_;
            auto cur_time = times[cur_vote];
            // cout << "cur_vote " << cur_vote << " cur_time " << cur_time << " cur_person " << cur_per << "" << endl;
            // PrintLinkList(llist);

            time2person_[cur_time] = max_person;
        }

    }
    
    int q(int t) {
        auto up_it = time2person_.upper_bound(t);
        int ret = 0;
        for (; ; up_it--) {
            if (up_it == time2person_.begin()) {
                break;
            }
            if (up_it == time2person_.end()) {continue;}
            auto cur_time = up_it->first;
            auto cur_person = up_it->second;
            if (cur_time <= t) {return cur_person;}
        }
        

        return ret;
    }
};

int main() {
    // vector<int> persons {0,1,1,0,0,1,0};
    // vector<int> times {0,5,10,15,20,25,30};
    // vector<int> persons {0,0,0,0,1};
    // vector<int> times {0,6,39,52,75};
    vector<int> persons {0,1,0,2,1,3,4,3,2,4};
    vector<int> times {9,14,17,25,32,66,80,82,88,99};
    // vector<int> persons {0,1};
    // vector<int> times {0,5};
    TopVotedCandidate s(persons, times);
    for(auto t2p: s.time2person_) {
        cout << "time " << t2p.first << "-> person " << t2p.second << endl;
    }

    // vector<int> inputs {3,12,25,15,24,8};
    // vector<int> inputs {45,49,59,68,42,37,99,26,78,43};
    vector<int> inputs {66,25,98,80,10,83,26,87,15,16,9,100,81,79,81,89,13,67,33,99};
    // vector<int> inputs {3, 6};
    for (auto input: inputs) {
        auto ret = s.q(input);
        cout << "q:" << input << ", then choose: " << ret << endl;
    }
    return 0;
}