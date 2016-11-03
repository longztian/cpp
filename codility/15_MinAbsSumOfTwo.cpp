// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <limits>

long solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();

    sort(A.begin(), A.end());

    int i = 0, j = N - 1;
    long sum, sumAbsMin = numeric_limits<long>::max();
    while (i <= j) {
        sum = A[i] + A[j];
        if (sum == 0) {
            return 0;
        } else if (sum < 0) {
            if (sum * -1 < sumAbsMin) sumAbsMin  = sum * -1;
            ++i;
        } else {
            if (sum < sumAbsMin) sumAbsMin = sum;
            --j;
        }
    }

    return sumAbsMin;
}
