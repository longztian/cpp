// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    int sum2, sum3, sum6, minSum, minI;

    minI = N - 2;
    minSum = (A[minI] + A[minI+1]) * 3 + 1; // add 1 here to avoid equal at lower indexes

    for (int i = 0; i < N - 2; ++i) {
        sum2 = A[i] + A[i+1];
        sum3 = sum2 + A[i+2];
        sum6 = sum2 * 3 < sum3 * 2 ? sum2 * 3 : sum3 * 2;
        if (sum6 < minSum) {
            minSum = sum6;
            minI = i;
        }
    }

    return minI;
}
