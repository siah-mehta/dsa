class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countValid(long long x, vector<int>& coins) {

        int n = coins.size();

        long long count = 0;

        // Enumerate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long LCM = 1;

            int bits = 0;

            bool tooLarge = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    LCM = lcm(LCM, coins[i]);

                    if (LCM > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long ways = x / LCM;

            if (bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long left = 1;

        // The kth valid amount cannot be greater
        // than k * smallest coin.
        long long right = 1LL * k * (*min_element(coins.begin(),
                                                    coins.end()));

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (countValid(mid, coins) >= k) {

                right = mid;

            } else {

                left = mid + 1;
            }
        }

        return left;
    }
};
    