// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> sum(6, A[0]);

    for (int i = 1; i < A.size(); ++i) {
        sum.push_back(*max_element(sum.rbegin(), sum.rbegin() + 6) + A[i]);
    }

    return sum.back();
}
