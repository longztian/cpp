// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
#include <iterator>

int solution(vector<int> &A) {
    int N = A.size();
    if (N == 0) return -1;
    if (N == 1) return 0;

    // write your code in C++11 (g++ 4.8.2)
    vector<int> stack;
    for (int v : A) {
        if (!stack.empty() && v != stack.back()) {
            stack.pop_back();
        } else {
            stack.push_back(v);
        }
    }

    if (stack.empty()) return -1;

    int n = count(A.begin(), A.end(), stack.back());

    return n > N / 2 ? distance(A.begin(), find(A.begin(), A.end(), stack.back())) : -1;
}
