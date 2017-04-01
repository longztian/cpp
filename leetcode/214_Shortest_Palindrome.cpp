class Solution {
public:
    string shortestPalindrome(string s) {
        const int N = s.size();
        if (N < 2) return s;

        reverse(s.begin(), s.end());

        auto pb = s.data(), pe = pb + s.size();
        while (pb < pe) {
            if (myIsPalindrome(pb, pe)) break;
            ++pb;
        }

        s.append(s.data(), pb);
        reverse(s.begin() + N, s.end());

        return s;
    }

private:
    bool myIsPalindrome(const char* pb, const char* pe) {
        while (pb < pe - 1) {
            --pe;
            if (*pb != *pe) return false;
            ++pb;
        }

        return true;
    }
};
