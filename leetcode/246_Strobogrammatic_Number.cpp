namespace {

unordered_map<char, char> digits({
  {'0', '0'},
  {'1', '1'},
  {'6', '9'},
  {'8', '8'},
  {'9', '6'}
});

}

class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char>::iterator it;

    for (auto i = num.data(), j = i + num.size() - 1; i <= j; ++i, --j) {
      it = digits.find(*i);
      if (it == digits.end() || it->second != *j) return false;
    }

    return true;
  }
};
