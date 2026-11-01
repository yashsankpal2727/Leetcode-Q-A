class Solution {
public:
    int mySqrt(int x) {
        long long l = -1;
        long long r = x * 1LL + 1;

        while (r - l > 1) {
            long long m = l + (r - l) / 2;
            if (m * m <= x) 
                l = m;
            else 
                r = m;
        }

        return l;
    }
};