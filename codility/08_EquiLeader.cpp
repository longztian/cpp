// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (N <= 1) return 0;
    if (N == 2) return A[0] == A[1] ? 1 : 0;

    vector<int> stack;
    for (int v : A) {
        if (!stack.empty() && v != stack.back()) {
            stack.pop_back();
        } else {
            stack.push_back(v);
        }
    }

    if (stack.empty()) return 0;
    int nLeader = count(A.begin(), A.end(), stack.back());
    if (nLeader <= N / 2) return 0;

    vector<int> count;
    int nSum = 0;
    for (int v : A) {
        if (v == stack.back()) nSum += 1;
        count.push_back(nSum);
    }

    int nEquiLeader = 0;
    for (int i = 0; i < N; ++i) {
        if (count[i] > (i + 1) / 2 && nLeader - count[i] > (N - 1 - i) / 2) nEquiLeader += 1;
    }

    return nEquiLeader;
}
