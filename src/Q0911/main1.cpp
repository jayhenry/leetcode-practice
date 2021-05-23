#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

class TopVotedCandidate {
public:
    map<int, int> time2person_;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        auto vote_num = persons.size();
        list<pair<int,int>> llist;
        // LinkNode* tail=NULL;

        map<int, list<pair<int,int>>::iterator> person2node;

        for(int cur_vote=0; cur_vote<vote_num; cur_vote++) {
            auto cur_per = persons[cur_vote];
            auto cur_time = times[cur_vote];
            // adjust rank by new vote
            // cout << "cur_vote " << cur_vote << " cur_time " << cur_time << " cur_person " << cur_per << "" << endl;
            auto it = person2node.find(cur_per);
            if (it == person2node.end()) {
                llist.emplace_back(cur_per, 1);
                auto lit = llist.end();
                lit --;
                person2node[cur_per] = lit;
            }
            else {
                auto cur_node = it->second;
                cur_node->second += 1;
            }

            it = person2node.find(cur_per);
            auto cur_it = it->second;
            auto new_it = it->second;
            while(1) {
                if((new_it->second) > (cur_it->second)) {new_it++; break;}
                if(new_it == llist.begin()) break;
                new_it --;
            }
            if (new_it != cur_it) {
                auto value = *(cur_it);
                llist.erase(cur_it);
                auto new_cur_it = llist.insert(new_it, value);
                person2node[cur_per] = new_cur_it;
            }

            // get candidate person at cur_time
            auto max_person = llist.begin()->first;
            // PrintLinkList(llist);

            time2person_[cur_time] = max_person;
        }

    }
    void PrintLinkList(list<pair<int,int>>& llist) {
        for(auto p: llist) {
            cout << "Person " << p.first <<" vote " << p.second << ",";
        }
        cout << endl;
    }
    
    int q(int t) {
        auto up_it = time2person_.upper_bound(t);
        up_it--;
        return up_it->second;
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