class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = INT_MAX;

        // Find minimum element
        for (int x : nums1) {
            mn = min(mn, x);
        }

        // If minimum is odd,
        // we can make every other element odd.
        if (mn % 2 == 1)
            return true;

        // Minimum is even.
        // Therefore final parity must be even.
        // Any odd number makes it impossible.
        for (int x : nums1) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};