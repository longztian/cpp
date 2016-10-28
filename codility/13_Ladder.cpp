// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

vector<int> solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    int maxA = *max_element(A.begin(), A.end());
    int pow30 = 1 << 30;
    vector<int> fab;
    fab.push_back(0);
    for (int i_2 = 0, i_1 = 1, i = i_1 + i_2; (int) fab.size() < maxA + 1; i_2 = i_1, i_1 = i, i = (i_1 + i_2) % pow30) fab.push_back(i);

    vector<int> ret;
    for (int i = 0, L = A.size(); i < L; ++i) {
        ret.push_back(fab[A[i]] % (1 << B[i]));
    }

    return ret;
}
