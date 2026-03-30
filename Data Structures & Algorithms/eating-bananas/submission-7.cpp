class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int pile : piles) {
            r = std::max(r, pile);
        }    
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (helperFunction(piles, h, mid)) {
                r = mid - 1;
                if (mid < ans) {
                    ans = mid;
                }
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    bool helperFunction(vector<int>& piles, int h, int mid) {
        long long time = 0;
        for (int pile : piles) {
            time += ((pile + mid - 1) / mid);
        }
        if (time <= h) {
            return true;
        } else {
            return false;
        }
    }
};
