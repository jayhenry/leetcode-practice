#include <list>
#include <utility>
#include <map>
#include <iostream>

using namespace std;


int main() {
    list<int> llist;
    map<int, list<int>::iterator> mymap;

    llist.push_back(1);
    auto it = llist.end();
    it --;
    mymap[1] = it;

    llist.push_back(2);
    it = llist.end();
    it --;
    mymap[2] = it;
    llist.push_back(3);
    it = llist.end();
    it --;
    mymap[3] = it;

    for(auto xy: mymap) {
        cout << "key " << xy.first << ", value " << *(xy.second) << endl;
    }



}