#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


void print_permutation(int n, int* P, int* A, int cur) {
    if (cur == n) {
        for(int i=0; i< n; i++) {
            cout << A[i];
        }
        cout << endl;
        return;
    }

    for(int i=0; i<n; i++) {
        if (i!=0 && P[i] == P[i-1]) continue;

        int c1 = 0;
        int c2 = 0;
        for(int j=0; j<cur; j++) {
            if (P[i] == A[j]) c2 ++;
        }
        for(int j=0; j<n; j++) {
            if (P[i] == P[j]) c1 ++;
        }
        if (c2 >= c1) continue;

        A[cur] = P[i];
        print_permutation(n, P, A, cur + 1);
    }
}


void print_subset(int n, int* A, int cur) {
    for(int i=0; i<cur; i++) cout << A[i];
    cout << endl;
    int s = cur ? A[cur-1] + 1 : 0;
    for (int i=s; i<n; i++) {
        A[cur] = i;
        print_subset(n, A, cur + 1);
    }
}


int main() {
    cout << "hello " << endl;

    // int P[] = {1,3,1};
    // int n = sizeof(P) / sizeof(P[0]);
    // int* A = new int[n];
    // sort(P, P + n);
    // print_permutation(n, P, A, 0);

    int n = 3;
    int* A = new int[n];
    print_subset(n, A, 0);
    delete A;
    return 0;
}