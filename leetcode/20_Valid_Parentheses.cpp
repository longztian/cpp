class Solution {
public:
    bool isValid(string s) {
        const int N = s.size();
        if (N % 2 != 0) return false;

        vector<char> stack;
        stack.reserve(N / 2);

        auto i = 0;
        for (auto c : s) {
            switch(c) {
                case '(': { if (stack.size() > N - i) return false; stack.push_back('('); break; }
                case '[': { if (stack.size() > N - i) return false; stack.push_back('['); break; }
                case '{': { if (stack.size() > N - i) return false; stack.push_back('{'); break; }
                case ')': { if (stack.empty() || stack.back() != '(') return false; stack.pop_back(); break; }
                case ']': { if (stack.empty() || stack.back() != '[') return false; stack.pop_back(); break; }
                case '}': { if (stack.empty() || stack.back() != '{') return false; stack.pop_back(); break; }
                default: return false;
            }
            ++i;
        }

        return stack.empty();
    }
};



class Solution {
public:
    bool isValid(string s) {
        if( s.empty() ) return true;

        // or use stack
        stack<char> st;
        for( auto p = s.data(), e = p + s.size(); p < e; ++p )
        {
            if( st.empty() )
            {
                switch( *p )
                {
                    case ')':
                    case ']':
                    case '}':
                        return false;
                        break;
                    case '(':
                    case '[':
                    case '{':
                        st.push( *p );
                        break;
                    default:
                        continue;
                }
            }
            else
            {
                switch( *p )
                {
                    case ')':
                        if( st.top() != '(' ) return false;
                        st.pop();
                        break;
                    case ']':
                        if( st.top() != '[' ) return false;
                        st.pop();
                        break;
                    case '}':
                        if( st.top() != '{' ) return false;
                        st.pop();
                        break;
                    case '(':
                    case '[':
                    case '{':
                        st.push( *p );
                        break;
                    default:
                        continue;
                }
            }
        }

        return st.empty();
    }
};
