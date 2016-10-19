// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    long max_slice = A[0], max_ending = A[0];
    for (int i = 1; i < N; ++i) {
        max_ending = max((long) A[i], max_ending + A[i]);
        max_slice = max(max_slice, max_ending);
    }

    return max_slice;
}
