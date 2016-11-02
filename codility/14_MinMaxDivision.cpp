// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int divide(const int iB, const int iE, const vector<int>& sum, const vector<int>& A, int k) {
    // cout << iB << " - " << iE << endl;
    if (k == 1) return sum[iE -1] - sum[iB] + A[iB];
    if (k >= iE - iB) return *max_element(A.data() + iB, A.data() + iE);

    auto iM = lower_bound(sum.data() + iB, sum.data() + iE, (sum[iB] + sum[iE -1]) / 2) - sum.data();
    return max(divide(iB, iM, sum, A, k / 2), divide(iM, iE, sum, A, k - k / 2));
}

int solution(int K, int M, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    if (K >= N) return *max_element(A.begin(), A.end());

    vector<int> sum;
    sum.reserve(N);
    int s = 0;
    for (int v : A) {
        s += v;
        sum.push_back(s);
    }

    return divide(0, A.size(), sum, A, K);
}
