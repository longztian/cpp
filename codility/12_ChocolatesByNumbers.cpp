// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int gcd(int a, int b) {
    int r = a % b;
    return r == 0 ? b : gcd(b, r);
}

int solution(int N, int M) {
    // write your code in C++11 (g++ 4.8.2)
    return N / gcd(N, M);
}