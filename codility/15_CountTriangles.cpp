// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 3) return 0;

    sort(A.begin(), A.end());

    int n = 0;
    for (int i = 0; i < N - 2; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < N - 1; ++j) {
            while (k < N && A[i] + A[j] > A[k]) ++k;
            n += (k - j - 1);
        }
    }
    return n;
}
