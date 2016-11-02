// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <unordered_set>
#include <cmath>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    unordered_set<int> s;
    for (int v : A) {
        s.insert(abs(v));
    }
    return s.size();
}
