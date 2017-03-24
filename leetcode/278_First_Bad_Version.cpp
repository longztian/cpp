// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:

    int dc( int b, int e )
    {
        // at least one bad version here, e

        // only 1 number
        if( b == e) return e;
        // only 2 numbers
        if( e - b == 1 )
        {
            return isBadVersion(b) ? b : e;
        }

        // more than two numbers
        // divide
        int m = b + ( e - b ) / 2;
        if( isBadVersion(m) )
        {
            // look for [b, m]
            return dc( b, m );
        }
        else
        {
            // look for [m+1, e]
            return dc( m + 1, e );
        }
    }
    int firstBadVersion(int n) {
        if( n < 1 ) return 0;
        return isBadVersion(n) ? dc( 1, n ) : 0;
    }
};



// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1 || !isBadVersion(n)) return -1;
        if (isBadVersion(1)) return 1;

        int begin = 1, end = n, mid = 0;
        while (begin < end - 1) {
            mid = begin + (end - begin) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                begin = mid;
            }
        }

        return end;
    }
};
