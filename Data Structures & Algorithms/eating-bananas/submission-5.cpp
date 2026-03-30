class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r;
        for (int pile : piles) {
            r = std::max(r, pile);
        }    
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (!helperFunction(piles, h, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
                if (mid < ans) {
                    ans = mid;
                }
            }
        }
        return ans;
    }

    bool helperFunction(vector<int>& piles, int h, int mid) {
        int time = 0;
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
