// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <cmath>

int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    int n = (int) sqrt(N);
    int nf = 0;
    for (int i = 1; i <= n; ++i) {
        if (N % i == 0) nf += 1;
    }
    return n * n == N ? nf * 2 - 1 : nf * 2;
}
