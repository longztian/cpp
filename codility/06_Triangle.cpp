// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// p = A[P], q = A[Q], r = A[R]
// p + q > r => p > r - q
// p + r > q => p > q - r = -(r - q)
// ==> p > 0,
// same ==> q > 0, r > 0

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 3) return 0;

    sort(A.begin(), A.end());

    // positive
    for (int i = 0; i < N - 2; ++i) {
        if (A[i] <= 0) continue;
        if ((long) A[i] + (long) A[i + 1] > (long) A[i + 2]) return 1;
    }

    return 0;
}
