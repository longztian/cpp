// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    int N = S.size();
    if (N == 0) return 1;
    if (N % 2 == 1) return 0;

    int n = 0;
    for (char c : S) {
        if (c == '(') {
            n += 1;
        } else {
            if (n == 0) return 0;
            n -= 1;
        }
    }
    return n == 0 ? 1 : 0;
}
