#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <boost/lambda/lambda.hpp>
#include <boost/pending/disjoint_sets.hpp>
#include <boost/property_map/property_map.hpp>
using namespace std;
using namespace boost;


int main() {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    // std::for_each(
        // in(std::cin), in(), std::cout << (_1 * 3) << " " );
    
    unordered_map<int, int> rank0;
    unordered_map<int, int> parent0;
    typedef associative_property_map<unordered_map<int,int>> PM;
    PM rank(rank0);
    PM parent(parent0);
    disjoint_sets<PM, PM> dset(rank, parent);
    vector<int> ints{1,2,3};
    dset.make_set(ints[0]);
    dset.make_set(ints[1]);
    dset.make_set(ints[2]);
    cout << "set count " << dset.count_sets(ints.begin(), ints.end()) << endl;
    dset.link(ints[0], ints[1]);

    cout << "set count " << dset.count_sets(ints.begin(), ints.end()) << endl;

    return 0;
}