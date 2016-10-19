// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    sort(A.begin(), A.end());
    return A[N-1] > 0 ? max(A[0] * A[1], A[N-3] * A[N-2]) * A[N-1]
                      : A[N-3] * A[N-2] * A[N-1];
}
