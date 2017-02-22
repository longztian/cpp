class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort( citations.begin(), citations.end() );

        int h;
        for( int i = 0, n = citations.size(); i < n; ++i )
        {
            h = n - i;
            if( citations[i] >= h ) return h;
        }

        return 0;
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        std::vector<int> counts(N + 1, 0);

        // count citation numbers
        for (auto c : citations) {
            if (c >= N) ++counts[N];
            else ++counts[c];
        }

        // scan
        int total = 0;
        for (int i = N; i >= 0; --i) {
            total += counts[i];
            if (total >= i) return i;
        }

        return 0;
    }
};
