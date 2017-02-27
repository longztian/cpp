class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if( n == 0 ) return;

        /*
        if( m + n - nums1.size() > 0 ) nums1.insert( nums1.end(), m + n - nums1.size(), 0 );

        if( m == 0 || nums1[m-1] <= nums2[0] )
        {
            copy( nums2.data(), nums2.data() + n, nums1.data() + m );
            return;
        }
        if( nums1[0] >= nums2[n-1] )
        {
            if( m <= n )
            {
                copy( nums1.data(), nums1.data() + m, nums1.data() + n );
            }
            else
            {
                copy( nums1.data() + ( m - n ), nums1.data() + m, nums1.data() + m );
                copy( nums1.data(), nums1.data() + ( m - n ), nums1.data() + n ) ;
            }

            copy( nums2.data(), nums2.data() + n, nums1.data() );
            return;
        }
        */

        vector<int> tmp;
        auto p1 = nums1.data(), e1 = nums1.data() + m, p2 = nums2.data(), e2 = nums2.data() + n;
        while( p1 < e1 && p2 < e2 )
        {
            if( *p1 < *p2 )
            {
                tmp.push_back( *(p1++) );
            }
            else
            {
                tmp.push_back( *(p2++) );
            }
        }

        if( p1 == e1 )
        {
            while( p2 < e2 )
            {
                tmp.push_back( *(p2++) );
            }
        }
        else
        {
            while( p1 < e1 )
            {
                tmp.push_back( *(p1++) );
            }
        }

        copy( tmp.data(), tmp.data() + m + n, nums1.data() );
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);

        const auto ITE2 = nums2.end();
        auto itb1 = nums1.begin(), itb2 = nums2.begin(), ite2 = ITE2;

        while (itb2 != ITE2) {
            itb1 = std::upper_bound(itb1, nums1.end(), *itb2);
            if (itb1 == nums1.end()) {
                nums1.insert(itb1, itb2, ITE2);
                itb2 = ITE2;
            } else {
                ite2 = std::upper_bound(itb2, ITE2, *itb1);
                nums1.insert(itb1, itb2, ite2);
                auto count = std::distance(itb2, ite2);
                itb1 += count;
                itb2 = ite2;
            }
        }
    }
};
