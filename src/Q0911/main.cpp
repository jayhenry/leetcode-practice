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
    map<int, int> time2person;
    map<int, int> person2vote;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        auto vote_num = persons.size();
        int best_person = -1, best_vote = 0;
        for(auto i=0; i<vote_num; ++i) {
            auto time = times[i];
            auto person = persons[i];
            person2vote[person] += 1;
            auto vote = person2vote[person];
            if (vote >= best_vote) {
                best_vote = vote;
                best_person = person;
            }
            time2person[time] = best_person;
        }
    }
    
    int q(int t) {
        auto it = time2person.upper_bound(t);
        it--;
        // cout << "For q(" << t <<"), time is " << it->first << endl;
        return it->second;
    }
};

int main() {
    // vector<int> persons {0,0,0,0,1};
    // vector<int> times {0,6,39,52,75};
    vector<int> persons {0,1,0,2,1,3,4,3,2,4};
    vector<int> times {9,14,17,25,32,66,80,82,88,99};
    // vector<int> persons {0,1};
    // vector<int> times {0,5};
    TopVotedCandidate s(persons, times);
    for(auto t2p: s.time2person) {
        cout << "time " << t2p.first << "-> person " << t2p.second << endl;
    }

    // vector<int> inputs {45,49,59,68,42,37,99,26,78,43};
    vector<int> inputs {66,25,98,80,10,83,26,87,15,16,9,100,81,79,81,89,13,67,33,99};
    // vector<int> inputs {3, 6};
    for (auto input: inputs) {
        auto ret = s.q(input);
        cout << "q:" << input << ", then choose: " << ret << endl;
    }
    return 0;
}