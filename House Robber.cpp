#include <vector>
#include <algorithm>
using namespace std;

int maxMoneyLooted(vector<int>& houses, int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return houses[0];
    }

    vector<int> dp(n, 0);
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);

    for (int i = 2; i < n; i++) {
        // At each house, we decide whether to rob it or not.
        // If we rob it, add the loot from this house and skip the previous one.
        // If we skip it, keep the previous loot.
        dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]);
    }

    return dp[n - 1];
}





