// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 2) return 0;

    vector<int> profit;
    profit.reserve(N-1);

    for (int i = 0; i < N - 1; ++i) {
        profit.push_back(A[i+1] - A[i]);
    }

    int max_slice = 0, max_end = 0;
    for (int p : profit) {
        max_end = max(0, max_end + p);
        max_slice = max(max_slice, max_end);
    }
    return max_slice;
}
