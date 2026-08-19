class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
       unordered_map<int, int> mp;

        for (auto &x : reservedSeats) {
            int row = x[0];
            int seat = x[1];

            if (seat >= 2 && seat <= 9) {
                mp[row] |= (1 << seat);
            }
        }

        long long ans = 2LL * n;

        int LEFT   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int MIDDLE = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int RIGHT  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : mp) {

            bool leftFree = (mask & LEFT) == 0;
            bool rightFree = (mask & RIGHT) == 0;

            if (leftFree && rightFree) {
                continue;       // still 2 families
            }

            if (leftFree || rightFree) {
                ans--;           // only 1 family
            }
            else if ((mask & MIDDLE) == 0) {
                ans--;           // middle gives 1 family
            }
            else {
                ans -= 2;        // no family
            }
        }

        return (int)ans;
    
    }
};