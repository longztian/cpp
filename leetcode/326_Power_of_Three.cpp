class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if ( n <= 3 ) return n == 3 || n == 1;

        while( n > 3 )
        {
            if( n % 3 ) return false;
            n /= 3;
        }

        return n == 3 || n == 1;
        */

        int max = pow(3, static_cast<int>(log(numeric_limits<int>::max()) / log(3)));
        return n > 0 && max % n == 0;
    }
};
