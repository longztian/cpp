class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.empty()) return -1;

        auto end = houses.end();
        int heaterE = heaters[0], heaterB = heaterE * (-1);
        auto pB = houses.begin(), pE = lower_bound(pB, end, heaterE);
        myGetMinRadius(pB, pE, heaterB, heaterE);

        for (int i = 0, n = heaters.size() - 1; i < n; ++i) {
            heaterB = heaterE;
            heaterE = heaters[i + 1];
            pB = upper_bound(pE, end, heaterB);
            pE = lower_bound(pB, end, heaterE);
            myGetMinRadius(pB, pE, heaterB, heaterE);
        }

        heaterB = heaterE;
        heaterE = heaterE + (houses.back() - heaters.back()) * 2;
        pB = upper_bound(pE, end, heaterB);
        pE = houses.end();
        myGetMinRadius(pB, pE, heaterB, heaterE);
    }

private:
    using IT = vector<int>::iterator;
    int myGetMinRadius(IT pB, IT, pE, int heaterB, int heaterE) {
        return 0;
    }
};
