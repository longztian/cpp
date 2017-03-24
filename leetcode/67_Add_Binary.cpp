class Solution {
public:
    string addBinary(string a, string b) {
        if( a.empty() ) return b;
        if( b.empty() ) return a;

        string ret( max(a.size(), b.size()) + 1, '0' );
        bool hasOne = false;

        auto pA = a.data() + a.size() - 1,
             pAE = a.data() - 1,
             pB = b.data() + b.size() - 1,
             pBE = b.data() - 1;

        int i = ret.size() - 1;

        while( pA > pAE && pB > pBE )
        {
            if( hasOne )
            {
                if( *pA == *pB )
                {
                    // 0 + 0 or 1 + 1
                    ret[i] = '1';
                    hasOne = ( *pA == '1' );
                }
                // 0 + 1, go to next digit
            }
            else
            {
                if( *pA == *pB )
                {
                    // 0 + 0 or 1 + 1
                    hasOne = ( *pA == '1' );
                }
                else
                {
                    ret[i] = '1';
                }
            }
            --pA;
            --pB;
            --i;
        }

        while( pA > pAE )
        {
            if( hasOne )
            {
                if( *pA == '0' )
                {
                    ret[i] = '1';
                    hasOne = false;
                }
            }
            else
            {
                ret[i] = *pA;
            }
            --pA;
            --i;
        }

        while( pB > pBE )
        {
            if( hasOne )
            {
                if( *pB == '0' )
                {
                    ret[i] = '1';
                    hasOne = false;
                }
            }
            else
            {
                ret[i] = *pB;
            }
            --pB;
            --i;
        }

        if( hasOne )
        {
            ret[0] = '1';
        }

        return hasOne ? ret : ret.substr( 1, ret.size() - 1 );
    }
};



class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) return addBinary(b, a);

        // a is longer string

        string sum(a.rbegin(), a.rend());
        sum.push_back('0');

        auto its = sum.begin();
        int carry = 0;
        for (auto it = b.rbegin(), ite = b.rend(); it != ite; ++it, ++its) {
            *its += (*it - '0' + carry);
            carry = 0;

            if (*its > '1') {
                *its = '0' + (*its - '0') % 2;
                carry = 1;
            }
        }

        for (auto itse = sum.end(); its != itse && carry > 0; ++its) {
            *its += carry;
            carry = 0;

            if (*its > '1') {
                *its = '0' + (*its - '0') % 2;
                carry = 1;
            }
        }

        if (sum.back() == '0') sum.pop_back();

        reverse(sum.begin(), sum.end());

        return sum;
    }
};
