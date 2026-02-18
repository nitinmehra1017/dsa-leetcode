class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;

        int start = 1, end = x, mid;
        int ans = 0;  // ✅ MUST initialize

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (mid == x / mid)  // exact sqrt
                return mid;

            else if (mid < x / mid) {
                ans = mid;          // ✅ store candidate
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};
