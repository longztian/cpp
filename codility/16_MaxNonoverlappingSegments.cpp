// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N < 2) return N;
    int n = 1, b = B[0];
    for (int i = 1; i < N; ++i) {
        if (A[i] > b) {
            b = B[i];
            n += 1;
        }
    }

    return n;
}
