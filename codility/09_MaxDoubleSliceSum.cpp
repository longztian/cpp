// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    int max_slice = 0, max_ending = 0;
    int Y = 1;

    for (int i = 2; i < N - 1; ++i) {
        if (A[i] < A[Y]) {
            max_ending += A[Y];
            Y = i;
        } else {
            max_ending += A[i];
        }

        if (max_ending < 0) {
            max_ending = 0;
            Y = i;
        }

        max_slice = max(max_slice, max_ending);
    }

    return max_slice;
}
