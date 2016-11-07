// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <limits>

int solution(int K, int M, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (K >= N) return *max_element(A.begin(), A.end());

    vector<int> sum;
    sum.reserve(N+1);
    sum.push_back(0);
    int maxV = numeric_limits<int>::min();
    for (int v : A) {
        sum.push_back(sum.back() + v);
        if (v > maxV) maxV = v;
    }

    int minSum = maxV;
    if (minSum * K < sum.back()) {
        minSum = sum.back() / K;
        if (sum.back() % K != 0) minSum += 1;
    }

    int minNK = numeric_limits<int>::max();
    for (int i = 0, j = N - K; j <= N; ++i, ++j) {
        if (sum[j] - sum[i]  < minNK) minNK = sum[j] - sum[i];
    }

    int maxSum = max(minSum, minNK);

    // greedy
    int i = minSum - 1, j = maxSum;
    while (i < j - 1) {
        // cout << i << j << endl;
        bool dividable = true;
        int m = i + (j - i) / 2;
        int n = 0, b = 0, e = b + 1;
        while (b < N) {
            while (e <= N && sum[e] - sum[b] <= m) ++e;
            n += 1;
            b = e - 1;
            if (n > K) {
                dividable = false;
                break;
            }
        }

        if (dividable) {
            j = m;
        } else {
            i = m;
        }
        // cout << i << j << endl;
    }

    return j;
}
