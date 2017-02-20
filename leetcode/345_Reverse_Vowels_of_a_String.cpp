namespace {
    std::unordered_set<char> myVowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
}

class Solution {
public:
    string reverseVowels(string s) {
        auto ret = s;
        auto pb = const_cast<char*>(ret.data());
        auto pe = pb + ret.size() - 1;

        const auto ITE = myVowels.cend();

        while (pb < pe) {
            // find vowel
            while (pb < pe && myVowels.find(*pb) == ITE) ++pb;
            while (pb < pe && myVowels.find(*pe) == ITE) --pe;
            if (pb < pe) {
                std::swap(*pb, *pe);
                ++pb;
                --pe;
            }
        }

        return ret;
    }
};
