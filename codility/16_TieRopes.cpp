// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int K, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int n = 0, sum = 0;
    for (int v : A) {
        sum += v;

        if (sum >= K) {
            sum = 0;
            n += 1;
        }
    }

    return n;
}
